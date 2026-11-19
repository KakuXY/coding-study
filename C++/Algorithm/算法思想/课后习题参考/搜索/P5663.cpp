/**
 * CSP-J2019
 * 加工零件
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> graph(n + 1);
  while (m --) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  auto min_dist = vector(n + 1, vector(2, INT_MAX));
  min_dist[1][0] = 0;
  queue<pair<int, int>> que;
  que.emplace(1, 0);
  while (!que.empty()) {
    auto [u, jiou] = que.front();
    int step = min_dist[u][jiou];
    que.pop();
    for (auto v : graph[u]) {
      if (min_dist[v][jiou ^ 1] <= step + 1) continue;
      min_dist[v][jiou ^ 1] = step + 1;
      que.emplace(v, jiou ^ 1);
    }
  }
  while (q--) {
    int a, l;
    cin >> a >> l;
    cout << (min_dist[a][l & 1] <= l ? "Yes" : "No") << endl;
  }
}