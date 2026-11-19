#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
  while (n --) {
    int x;
    cin >> x;
    for (int i = a; i >= 0; i --) {
      for (int j = b; j >= 0; j --) {
        if (i >= x) dp[i][j] = max(dp[i][j], dp[i - x][j] + x);
        if (j >= x) dp[i][j] = max(dp[i][j], dp[i][j - x] + x);
      }
    }
  }
  cout << dp[a][b] << endl;
}