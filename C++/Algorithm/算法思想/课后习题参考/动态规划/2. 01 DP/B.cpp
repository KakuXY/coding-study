#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;


constexpr int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (accumulate(a.begin(), a.end(), 0) & 1) {
      cout << 0 << endl;
      continue;
    }
    vector<array<int, 2>> dp(2);
    // f(i, 0) 偶数
    // f(i, 1) 奇数
    dp[1] = {1, 0};
    for (int i = 0; i < n; i ++) {
      auto &cur = dp[i & 1], &his = dp[~i & 1];
      if (a[i] & 1) {
        cur[0] = (his[0] + his[1]) % mod;
        cur[1] = (his[1] + his[0]) % mod;
      } else {
        cur[0] = (his[0] + his[0]) % mod;
        cur[1] = (his[1] + his[1]) % mod;
      }
    }
    cout << dp[~n & 1][0] << endl;
  }
}