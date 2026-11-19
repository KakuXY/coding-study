#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n, vector<int>(n));
    for (auto &line : w) {
      for (auto &x : line) cin >> x;
    }
    vector<int> pos(m);
    for (auto &p : pos) cin >> p, p --;


    const int inf = INT_MAX / 2;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, inf)));
    if (pos[0] != 0 && pos[0] != 1) dp[0][0][1] = w[2][pos[0]];
    if (pos[0] != 0 && pos[0] != 2) dp[0][0][2] = w[1][pos[0]];
    if (pos[0] != 1 && pos[0] != 2) dp[0][1][2] = w[0][pos[0]];

    for (int i = 0; i < m - 1; i ++) {
      auto &cur = dp[i & 1], &nxt = dp[~i & 1];
      for (int x = 0; x < n; x ++) fill(nxt[x].begin(), nxt[x].end(), inf);
      for (int x = 0; x < n; x ++) {
        for (int y = x + 1; y < n; y ++) {
          // x, y, pos[i] ->   pos[i+1], y, pos[i]
          //              ->   x, pos[i+1], pos[i]
          //              ->   x, y, pos[i+1]
          auto update = [&](int nx, int ny, int w) {
            if (nx == pos[i+1] || ny == pos[i+1]) return;
            if (nx > ny) swap(nx, ny);
            nxt[nx][ny] = min(nxt[nx][ny], cur[x][y] + w);
          };
          update(y, pos[i], w[x][pos[i+1]]);
          update(x, pos[i], w[y][pos[i+1]]);
          update(x, y, w[pos[i]][pos[i+1]]);
        }
      }
    }
    int ans = INT_MAX;
    for (int x = 0; x < n; x ++) {
      ans = min(ans, *min_element(dp[~m & 1][x].begin(), dp[~m & 1][x].end()));
    }
    cout << ans << endl;
  }
}