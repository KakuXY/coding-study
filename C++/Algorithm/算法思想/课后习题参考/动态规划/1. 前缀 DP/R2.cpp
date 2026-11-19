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
    vector<array<int, 2>> mul(n + 1);
    vector<int> add(n + 1);
    for (int i = 1; i <= n; i ++) {
      for (int j = 0; j < 2; j ++) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') add[i] += x;
        else mul[i][j] = x - 1;
      }
    }
    vector<array<i64, 2>> dp(n + 1);
    dp[n] = {1, 1};
    for (int i = n; i >= 1; i --) {
      for (int k = 0; k < 2; k ++) {
        dp[i - 1][k] = dp[i][k] + mul[i][k] * max(dp[i][0], dp[i][1]);
      }
    }
    i64 ans = dp[0][0] + dp[0][1];
    for (int i = 1; i <= n; i ++) {
      ans += add[i] * max(dp[i][0], dp[i][1]);
    }
    cout << ans << endl;
  }
}