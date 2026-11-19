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
  vector<vector<int>> w(n, vector<int>(m));
  for (auto & line : w) for (auto &x : line) cin >> x;
  const i64 inf = LLONG_MIN / 2;
  vector<i64> up(n, inf), down(n, inf);
  up[0] = 0;
  for (int i = 0; i < m; i ++) {
    for (int j = 0; j < n; j ++) {
      up[j] = down[j] = max(up[j], down[j]) + w[j][i];
    }
    for (int j = 1; j < n; j ++) {
      down[j] = max(down[j], down[j - 1] + w[j][i]);
    }
    for (int j = n - 2; j >= 0; j --) {
      up[j] = max(up[j], up[j + 1] + w[j][i]);
    }
  }
  cout << down[n - 1] << endl;
}