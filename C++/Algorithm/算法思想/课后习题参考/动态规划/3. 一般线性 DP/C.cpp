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
  struct Pos { int t, x, y; };
  vector<Pos> pos(m);
  for (auto &[t, x, y]: pos) cin >> t >> x >> y;
  auto dis = [&](int i, int j) {
    return abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y);
  };
  vector<int> dp(m, 1);
  for (int i = 1; i < m; i ++) {
    for (int j = 0; j < i; j ++) {
      if (dis(i, j) <= pos[i].t - pos[j].t) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}