#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while(T --) {
    int n;
    cin >> n;
    vector<array<pair<i64, i64>, 2>> dp(n + 1);
    dp[0][0] = dp[0][1] = {1, 1};
    for (int i = 0; i < n; i ++) {
      char op1, op2;
      int v1, v2;
      cin >> op1 >> v1 >> op2 >> v2;
      for (int k = 0; k < 2; k ++) {
        // 0 left Max
        // 1 right Max
        i64 addition = 0;
        if (op1 == '+') addition += v1;
        else addition += dp[i][k].first * (v1 - 1);
        if (op2 == '+') addition += v2;
        else addition += dp[i][k].second * (v2 - 1);

        pair<i64, i64> a = {dp[i][k].first + addition, dp[i][k].second};
        pair<i64, i64> b = {dp[i][k].first, dp[i][k].second + addition};
        array<pair<i64, i64>, 2> cands = {a, b};
        for (auto cand : cands) {
          dp[i + 1][0] = max(dp[i + 1][0], cand);
          if (cand.second > dp[i + 1][1].second ||
              (cand.second == dp[i + 1][1].second && cand.first > dp[i + 1][1].first)) {
                dp[i + 1][1] = cand;
              }
        }
      }
    }
    cout << max(dp[n][0].first + dp[n][0].second, dp[n][1].first + dp[n][1].second) << endl;
  }
}