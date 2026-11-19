#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k, c, w;
  cin >> n >> k >> c >> w;
  vector<pair<int, int>> a(n);
  for (auto &[type, x] : a) cin>> type >> x;
  reverse(a.begin(), a.end());
  double dp = 0;
  for (auto [type, x] : a) {
    if (type == 1) {
      dp = max(dp, x * w + dp * (1 - 0.01 * k));
    } else {
      dp = max(dp, -x * w + dp * (1 + 0.01 * c));
    }
  }
  cout << fixed << setprecision(2) << dp << endl;
}