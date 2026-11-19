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
  vector<int> dp(n + 1, INT_MIN);
  dp[0] = 0;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    for (int j = n; j >= 1; j --) {
      dp[j] = max(dp[j], dp[j - 1] + (j == x));
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}