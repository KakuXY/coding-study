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
  vector<pair<int, int>> a(n);
  for (auto &[r, w] : a) cin >> w >> r;
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  vector<int> dp(n + 1);
  for (auto &[r, w] : a) {
    for (int i = n; i >= 1; i --) {
      dp[i] = max(dp[i], dp[i - 1] + w - r * (i - 1));
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}