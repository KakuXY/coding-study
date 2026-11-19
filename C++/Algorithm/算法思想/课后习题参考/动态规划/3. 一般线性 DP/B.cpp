#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int ans = 1;
  for (int diff = 1; diff <= n; diff ++) {
    vector<int> dp(n + 1, 1);
    for (int i = diff; i <= n; i ++) {
      if (a[i - diff] < a[i]) {
        dp[i] = dp[i - diff] + 1;
        ans = max(ans, dp[i]);
      }
    }
  }
  cout << ans << endl;
}