#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

template<typename T>
class SPFA {
  using edge = pair<T, int>;
  vector<vector<edge>> g;
  vector<size_t> cnt;
  vector<int> in_queue;
 public:
  SPFA(int n) : g(n + 1), cnt(n + 1), in_queue(n + 1) {}
  void add_edge(int u, int v, T w) {
    g[u].emplace_back(v, w);
  }
  // 不传起点，可以直接跑一个无源负环检测
  pair<bool, vector<T>> run(int s = -1) {
    vector<T> dist(g.size(), numeric_limits<T>::max());
    queue<int> q;
    auto try_update = [&](int u, T val) {
      dist[u] = val;
      if (in_queue[u]) return;
      in_queue[u] = 1;
      q.push(u);
    };
    if (s == -1) {
      for (size_t i = 1; i < g.size(); i++) {
        try_update(i, 0);
      }
    } else {
      try_update(s, 0);
    }
    while (q.size()) {
      int u = q.front();
      q.pop();
      in_queue[u] = 0;
      for (auto [v, w] : g[u]) {
        if (dist[v] > dist[u] + w) {
          cnt[v] = cnt[u] + 1;
          if (cnt[v] > g.size()) {
            return {false, dist};
          }
          try_update(v, dist[u] + w);
        }
      }
    }
    return {true, dist};
  }
};


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  SPFA<i64> spfa(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    spfa.add_edge(u, v, w);
  }
  auto [ok, dist] = spfa.run(s);
  if (!ok) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i] == numeric_limits<i64>::max()) {
      cout << "INF";
    } else {
      cout << dist[i] << ' ';
    }
  }
}