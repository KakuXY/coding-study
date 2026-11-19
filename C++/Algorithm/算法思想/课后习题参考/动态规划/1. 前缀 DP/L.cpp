#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int mod = 1e9 + 7;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x : arr) cin >> x;
  int ans = 0;
  for (int f = 0; f <= 10; f ++) {
    for (int s = 0; s <= 10; s ++) {
      vector<array<array<int, 11>, 11>> dp(2);
      dp[1][f][s] = 1;
      for (int i = 2; i < n; i ++) {
        auto &cur = dp[i & 1], &pre = dp[~i & 1];
        for (int a = 0; a <= 10; a ++) {
          for (int b = 0; b <= 10; b ++) {
            cur[b][a] = 0;
            for (int c = 0; c <= 10; c ++) {
              if (max({a, b, c}) != arr[i - 1]) continue;
              cur[b][a] = (cur[b][a] + pre[c][b]) % mod;
            }
          }
        }
      }

      for (int b = 0; b <= 10; b ++) {
        for (int a = 0; a <= 10; a ++) {
          if (arr[0] != max({f, s, a})) continue;
          if (arr[n - 1] != max({a, b, f})) continue;
          ans = (ans + dp[~n & 1][b][a]) % mod;
        }
      }
    }
  }
  cout << ans << endl;
}