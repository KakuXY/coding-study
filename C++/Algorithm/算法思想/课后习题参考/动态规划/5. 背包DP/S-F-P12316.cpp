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
  vector<i64> dp(m + 1, 0);
  while (n --) {
    i64 a;
    cin >> a;
    for (int i = m; i >= 0; i --) {
      for (int j = 0; j <= min(i, 31); j ++) {
        unsigned lower = a << j;
        unsigned upper = a >> (32 - j);
        dp[i] = max(dp[i], dp[i - j] + lower + upper);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}