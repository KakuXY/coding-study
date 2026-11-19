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
  vector<int> dp(n, 1);
  for (int i = 1; i < n; i ++) {
    for (int j = 0; j < i; j ++) {
      if (a[i] > a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}