#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int mod = 998244353;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> dp(10000);

  for (int a = 1; a <= 9; a += 2) {
    for (int b = 0; b <= 9; b += 2) {
      for (int c = 1; c <= 9; c += 2) {
        for (int d = 0; d <= 9; d += 2) {
          dp[a * 1000 + b * 100 + c * 10 + d] = 1;
        }
      }
    }
  }

  for (int i = 4; i < n; i ++) {
    int p = i % 2;
    for (int b = p; b <= 9; b += 2) {
      for (int c = 1 - p ; c <= 9; c += 2) {
        for (int d = p; d <= 9; d += 2) {
          int bcd = b * 100 + c * 10 + d;
          for (int e = 1 - p; e <= 9; e += 2) {
            int &res = dp[bcd * 10 + e];
            res = 0;
            for (int a = 1 - p; a <= 9; a += 2) {
              if (a + b + c + d + e > m) continue;
              res = (res + dp[a * 1000 + bcd]) % mod;
            }
          }
        }
      }
    }
  }

  int ans = 0;
  int p = (n - 1) % 2;
  for (int a = p; a <= 9; a += 2) {
    for (int b = 1 - p; b <= 9; b += 2) {
      for (int c = p; c <= 9; c += 2) {
        for (int d = 1 - p; d <= 9; d += 2) {
          ans = (ans + dp[a * 1000 + b * 100 + c * 10 + d]) % mod;
        }
      }
    }
  }
  cout << ans << endl;
}