#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  auto graph = vector(n + 1, vector<pair<int, int>>());
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[u].emplace_back(v, c);
  }
  using pii = pair<int, int>; // distance, u
  priority_queue<pii, vector<pii>, greater<pii>> q;
  auto min_dist = vector(n + 1, INT_MAX);
  auto calced = vector(n + 1, 0);
  min_dist[s] = 0;
  q.emplace(0, s);
  debug(graph);
  while (!q.empty()) {
    auto [dist, u] = q.top();
    debug(q.top());
    q.pop();
    if (calced[u]) continue;
    calced[u] = true;
    for (auto [v, c]: graph[u]) {
      if (min_dist[v] <= min_dist[u] + c) continue;
      min_dist[v] = min_dist[u] + c;
      q.emplace(min_dist[u] + c, v);
    }
  }
  for (int i = 1; i <= n; i ++) cout << min_dist[i] << ' ';
}