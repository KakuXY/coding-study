#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t, m;
  cin >> t >> m;
  vector<i64> dp(t + 1);
  while (m --) {
    int v, w;
    cin >> v >> w;
    for (int i = v; i <= t; i ++) {
      dp[i] = max(dp[i], dp[i - v] + w);
    }
  }
  cout << dp[t] << endl;
}