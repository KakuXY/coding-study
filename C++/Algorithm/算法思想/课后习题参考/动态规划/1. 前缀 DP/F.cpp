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
  vector<string> str(n);
  for (auto &s : str) cin >> s;
  vector<array<int, 2>> dp(2);
  for (int i = 0; i < n; i ++) {
    auto &cur = dp[i&1] , &pre = dp[~i&1];
    if (i == 0) {
      cur = {2, 2};
      continue;
    }
    for (int c = 0; c < 2; c ++) {
      cur[c] = INT_MAX;
      for (int p = 0; p < 2; p ++) {
        // str[i - 1][1 - p]  str[i][c] == 1 != 2
        cur[c] = min(cur[c], pre[p] + 1 + (str[i - 1][1 - p] != str[i][c]));
      }
    }
  }
  cout << min(dp[~n&1][0], dp[~n&1][1]) << endl;
}