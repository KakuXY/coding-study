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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> dp(n, INT_MIN);
  for (int i = 0; i < n; i ++) {
    if (i == 0) dp[i] = a[i];
    else dp[i] = max(dp[i - 1] + a[i], a[i]);
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}