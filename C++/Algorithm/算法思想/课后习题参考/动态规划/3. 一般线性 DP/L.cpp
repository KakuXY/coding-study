#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n;
    cin >> n;
    vector<i64> sum(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
      cin >> a[i];
      sum[i] = sum[i - 1] + (a[i] == a[i - 1] ? a[i] : 0);
    }
    vector<int> lastPos(1e6 + 1, -1);
    vector<i64> dp(n + 1);
    for (int i = 1; i <= n; i ++) {
      dp[i] = dp[i - 1];
      if (lastPos[ a[i] ] != -1) {
        int j = lastPos[ a[i] ];
        // a[i]  ==  a[j];
        i64 w = i == j + 1 ? 0 : sum[i - 1] - sum[j + 1];
        dp[i] = max(dp[i], dp[j + 1] + a[i] + w);
      }
      lastPos[ a[i] ] = i;
    }
    cout << dp[n] << endl;
  }
}