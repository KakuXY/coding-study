#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

constexpr int inf = INT_MIN / 2;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i];
  }
  vector<int> sum(n + 1);
  partial_sum(a.begin(), a.end(), sum.begin());
  vector<int> dp(n + 1, inf);
  dp[0] = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = 0; j < i; j ++) {
      if (sum[i] - sum[j] >= 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  debug(dp);
  if (dp[n] < 0) cout << "Impossible" << endl;
  else cout << dp[n] << endl;
}