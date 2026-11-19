#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) cin >> a[i];
  int m;
  cin >> m;
  string str;
  cin >> str;
  vector<int> dp(m);
  for (int i = 1; i < m; i ++) {
    dp[i] = dp[i - 1];
    for (int k = 1; k <= n && i - k * 3 >= -1; k ++) {
      int j = i - k * 3;
      if (str[j + 1] == 'a' && str[j + 2] == 'b' && str[j + 3] == 'c') {
        if (j == -1) dp[i] = max(dp[i], a[k]);
        else dp[i] = max(dp[i], dp[j] + a[k]);
      } else {
        break;
      }
    }
  }
  cout << dp[m - 1] << endl;
}