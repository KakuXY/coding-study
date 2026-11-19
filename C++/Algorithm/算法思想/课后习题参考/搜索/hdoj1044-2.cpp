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
    auto get_id = [&](int x, int y) {
      if (maze[x][y] == '@') return 0;
      if (isalpha(maze[x][y])) return maze[x][y] - 'A' + 1;
      if (maze[x][y] == '<') return m + 1;
      return -1;
    };
    vector<vector<int>> graph(m + 2, vector<int>(m + 2, -1));
    auto build_graph = [&](int sx, int sy) {
      vector<vector<int>> min_dist(h, vector<int>(w, INT_MAX));
      queue<pair<int, int>> q;
      int id = get_id(sx, sy);
      q.emplace(sx, sy);
      min_dist[sx][sy] = 0;
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int step = min_dist[x][y];
        if (get_id(x, y) != -1) graph[id][get_id(x, y)] = step;
        for (auto [dx, dy] : dirs) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
          if (maze[nx][ny] == '*') continue;
          if (min_dist[nx][ny] <= step + 1) continue;
          min_dist[nx][ny] = step + 1;
          q.emplace(nx, ny);
        }
      }
    };
    for (int i = 0; i < h; i ++) {
      for (int j = 0; j < w; j ++) {
        if (get_id(i, j ) != -1) build_graph(i, j);
      }
    }
    debug(graph);

    vector<vector<int>> min_dist(m + 2, vector<int>(1 << m, INT_MAX));
    vector<vector<int>> calced(m + 2, vector<int>(1 << m));
    using State = tuple<int, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.emplace(0, 0, 0);
    min_dist[0][0] = 0;
    while (!pq.empty()) {
      auto [step, u, picked] = pq.top();
      pq.pop();
      if (calced[u][picked]) continue;
      calced[u][picked] = true;
      for (int v = 0; v < m + 2; v ++) {
        if (graph[u][v] == -1) continue;
        int np = picked;
        if (1 <= v && v <= m) np |= 1 << (v - 1);
        if (min_dist[v][np] <= step + graph[u][v]) continue;
        min_dist[v][np] = step + graph[u][v];
        pq.emplace(step + graph[u][v], v, np);
      }
    }
    debug(min_dist);
    int ans = -1;
    for (int picked = 0; picked < (1 << m); picked ++) {
      if (min_dist[m+1][picked] > l) continue;
      int sum = 0;
      for (int i = 0; i < m; i ++) {
        if (picked & (1 << i)) sum += vals[i];
      }
      ans = max(ans, sum);
    }

    printf("Case %d:\n", cas);
    if (ans == -1) puts("Impossible");
    else printf("The best score is %d.\n", ans);
    puts("");
  }
}