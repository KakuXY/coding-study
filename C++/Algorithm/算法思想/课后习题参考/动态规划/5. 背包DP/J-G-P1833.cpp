#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int sh, sm, eh, em, n;
  scanf("%d:%d %d:%d %d", &sh, &sm, &eh, &em, &n);
  int m = eh * 60 + em - sh * 60 - sm;
  vector<int> dp(m + 1);
  while (n --) {
    int t, c, p;
    cin >> t >> c >> p;
    if (p) {
      auto calc = [&](int v, int w) {
        for (int i = m; i >= v; i --) {
          dp[i] = max(dp[i], dp[i - v] + w);
        }
      };
      for (int cnt = 1; p >= cnt; p -= cnt, cnt *= 2) {
        calc(cnt * t, cnt * c);
      }
      calc(p * t, p * c);
    } else {
      for (int i = t; i <= m; i ++) {
        dp[i] = max(dp[i], dp[i - t] + c);
      }
    }
  }
  cout << dp[m] << endl;
}