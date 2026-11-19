#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  int n;
  while (cin >> n) {
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i ++) cin >> arr[i];
    int nn = n / 2;
    vector<vector<int>> dp(n + 1, vector<int>(nn + 1, INT_MAX));
    dp[1][1] = -1;
    // (1, 0, arr[1], -1)   ->   [ arr[1] ], []
    for (int i = 1; i < n; i ++) {
      for (int j = 1; j <= nn; j ++) {
        // dp[i][j] = x;
        // (j, arr[i])   (i - j, dp[i][j])
        if (arr[i + 1] > arr[i] && j + 1 <= nn) {
          dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        }
        int k = i - j;
        if (arr[i + 1] > dp[i][j] && k >= 0 && k < nn) {
          dp[i + 1][k + 1] = min(dp[i + 1][k + 1], arr[i]);
        }
      }
    }
    cout << (dp[n][nn] == INT_MAX ? "No!" : "Yes!") << endl;
  }

}