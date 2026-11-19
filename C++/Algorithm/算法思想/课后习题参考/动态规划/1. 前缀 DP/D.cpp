#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  char pid;
  cin >> pid;
  if (pid == 'A') {
    cout << 4430091 << endl;
    return 0;
  }
  vector<vector<i64>> dp(31, vector<i64>(11, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= 30; i ++) {
    for (int s = 0; s <= 10; s ++) {
      if (s == 0) {
        dp[i][s] = accumulate(dp[i - 1].begin(), dp[i - 1].end() - 1, 0ll);
      } else {
        dp[i][s] = dp[i - 1][s - 1];
      }
    }
  }
  long long sum = 0;
  for (int i = 1; i <= 30; i ++) {
    sum += dp[i][7];
  }
  cout << sum << endl;
}