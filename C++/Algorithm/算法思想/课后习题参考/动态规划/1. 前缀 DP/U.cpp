#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int mod = 998244353;
int dp[102][31][31][16]; // 第 i 个选项，用了 j 个字数，有 k 个不能改变的 1，产生 c 个进位

int main() {
  long long C[31][31];
  for (int i = 0; i <= 30; i ++) {
    for (int j = 0 ; j <= i; j ++) {
      if (j == 0 || j == i) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  cin.tie(0)->sync_with_stdio(0);
  int n, m, K;
  cin >> n >> m >> K;
  dp[0][0][0][0] = 1;
  for (int i = 0; i <= m; i ++) {
    int v;
    cin >> v;
    vector<long long> pow(n + 1, 1);
    for (int j = 1; j <= n; j ++) pow[j] = pow[j - 1] * v % mod;
    debug(pow);
    for (int j = 0; j <= n; j ++) { // 使用了 j 个数字
      for (int k = 0; k <= K; k ++) { // k 位的 1
        for (int c = 0; c <= n / 2; c ++) { // 进位
          // dp[i][j][k][c] -> 
          if (dp[i][j][k][c] == 0) continue;
          for (int s = 0; s <= n - j; s++) {
            int n_k = k + (s + c) % 2;
            if (n_k > K) continue;
            int n_c = (s + c) / 2;
            dp[i + 1][j + s][n_k][n_c] += dp[i][j][k][c] * pow[s] % mod * C[n - j][s] % mod;
            dp[i + 1][j + s][n_k][n_c] %= mod;
          }
        }
      }
    }
  }
  int ans = 0;
  // dp[m + 1][n][k][c];
  for (int k = 0; k <= K; k ++) {
    for (int c = 0; c <= n / 2; c ++) {
      if (__builtin_popcount(c) + k <= K) {
        ans += dp[m + 1][n][k][c];
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
}