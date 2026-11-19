template<typename T>
class Dijkstra {
  using edge = pair<T, int>;
  vector<vector<edge>> g;
  vector<int> vis;
 public:
  Dijkstra(int n) : g(n + 1), vis(n + 1) {}
  void add_edge(int u, int v, T w) {
    g[u].emplace_back(v, w);
  }
  vector<T> run(int s) {
    priority_queue<edge, vector<edge>, greater<edge>> q;
    vector<T> dist(g.size(), numeric_limits<T>::max());
    fill(vis.begin(), vis.end(), 0);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
      auto [d, u] = q.top();
      q.pop();
      if (vis[u]) continue;
      vis[u] = 1;
      for (auto [v, w] : g[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          q.emplace(dist[v], v);
        }
      }
    }
    return dist;
  }
};