#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dirs = {
  {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    int w, h, l, m;
    cin >> w >> h >> l >> m;
    vector<string> maze(h);
    vector<int> vals(m);
    for (auto &v : vals) cin >> v;
    for (auto &line : maze) cin >> line;
    vector<vector<vector<int>>> min_dist(h, vector<vector<int>>(w, vector<int>(1 << m, INT_MAX)));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < h; i ++) {
      for (int j = 0; j < w; j ++) {
        if (maze[i][j] == '@') {
          q.emplace(i, j, 0);
          min_dist[i][j][0] = 0;
        }
      }
    }
    int ans = -1;
    while (!q.empty()) {
      auto [x, y, picked] = q.front();
      q.pop();
      int step = min_dist[x][y][picked];
      if (maze[x][y] == '<') {
        int sum = 0;
        for (int i = 0; i < m; i ++) {
          if (picked & (1 << i)) sum += vals[i];
        }
        ans = max(ans, sum);
      }
      if (step == l) continue;
      for (auto [dx, dy] : dirs) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (maze[nx][ny] == '*') continue;
        int np = picked;
        if (isalpha(maze[nx][ny])) np |= 1 << (maze[nx][ny] - 'A');
        if (min_dist[nx][ny][np] <= step + 1) continue;
        min_dist[nx][ny][np] = step + 1;
        q.emplace(nx, ny, np);
      }
    }

    printf("Case %d:\n", cas);
    if (ans == -1) puts("Impossible");
    else printf("The best score is %d.\n", ans);
    puts("");
  }
}