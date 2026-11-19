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
  vector<int> dp(n);
  for (int i = 0; i < n; i ++) {
    int v = str[i] - 'a' + 1;
    if (i == 0) dp[i] = v;
    else if (i == 1) dp[i] = max(dp[i - 1], v);
    else dp[i] = max(dp[i - 1], dp[i - 2] + v);
  }
  cout << dp[n - 1] << endl;
}