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
  vector<array<int, 2>> elems(n);
  for (int i = 0; i < 2; i ++) {
    for (auto &elem : elems) {
      int x;
      cin >> x;
      for (; x; x /= 10) {
        int digit = x % 10;
        if (digit <= 4 && digit % 2 == 0) {
          // 0 2 4
          // 1 << 0 , 1 << 1, 1 << 2
          elem[i] |= 1 << (digit / 2);
        }
      }
    }
  }
  constexpr int inf = INT_MIN / 2;
  vector<array<int, 3>> dp(2, {inf, inf, inf});
  for (auto &elem : elems) {
    array<int, 2> maxv;
    for (int t = 0; t <= 1; t ++) {
      maxv[t] = t == 0 ? 0 : INT_MIN;
      for (int i = 0; i < 3; i ++) {
        if (elem[t] >> i & 1) { // 0: 0, 1 : 2, 2 : 4
          maxv[t] = max(maxv[t], dp[t ^ 1][i]);
        }
      }
    }
    for (int t = 0; t <= 1; t ++) {
      for (int i = 0; i < 3; i ++) {
        if (elem[t] >> i & 1) {
          dp[t][i] = max(dp[t][i], maxv[t] + 1);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; i ++) {
    ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
  }
  cout << ans << endl;
}