#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string str;
  cin >> str;
  int n = str.size();
  vector<vector<int>> dp(2, vector<int>(2));
  for (int i = 0; i < n; i ++) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    int v = str[i] - 'a' + 1;
    if (i == 0) {
      cur[0] = 0;
      cur[1] = v;
    } else {
      cur[0] = max(pre[0], pre[1]);
      cur[1] = pre[0] + v;
    }
  }
  cout << max(dp[~n & 1][0], dp[~n & 1][1]) << endl;
}