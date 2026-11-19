#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1);
  dp[0] = 1;
  while (n --) {
    int x;
    cin >> x;
    for (int i = m; i >= x; i --) {
      dp[i] += dp[i - x];
    }
  }
  cout << dp[m] << endl;
}