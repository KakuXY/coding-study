#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int mod = 998244353;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int offset = 2e4;
  vector<vector<int>> dp(n, vector<int>(offset * 2 + 1));
  int ans = n;
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < i; j ++) {
      int diff = a[i] - a[j] + offset;
      dp[i][diff] = (dp[i][diff] + dp[j][diff] + 1) % mod;
      ans = (ans + dp[j][diff] + 1) % mod;
    }
  }
  cout << ans << endl;
}