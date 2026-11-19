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
  auto same = [&](int i, int j) {
    if (str[i] == str[j]) return true;
    if (str[i] == '?' || str[j] == '?') return true;
    return false;
  };
  for (int i = 1; i < n; i ++) {
    if (i == 1) dp[i] = same(i, i - 1);
    else dp[i] = max(dp[i - 1], dp[i - 2] + same(i, i - 1));
  }
  cout << dp[n - 1] << endl;
}