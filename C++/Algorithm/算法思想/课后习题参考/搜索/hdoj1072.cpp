#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    auto maze = vector(n, vector(m, 0));
    int sx, sy;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        cin >> maze[i][j];
        if (maze[i][j] == 2) {
          sx = i;
          sy = j;
        }
      }
    }
    auto bfs = [&]() {
      auto min_dist = vector(n, vector(m, vector(7, INT_MAX)));
      queue<tuple<int, int, int>> q;
      
      auto try_push = [&](int x, int y, int k, int step, int &pre) {
        if (pre <= step) return;
        min_dist[x][y][k] = step;
        q.emplace(x, y, k);
      };
      q.emplace(sx, sy, 6);
      min_dist[sx][sy][6] = 0;
      while (!q.empty()) {
        auto [x, y, k] = q.front();
        q.pop();
        int step = min_dist[x][y][k];
        if (maze[x][y] == 3) return step;
        if (k == 1) continue;
        for (auto [dx, dy] : dir) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (maze[nx][ny] == 0) continue;
          int nextk = k - 1;
          if (maze[nx][ny] == 4) nextk = 6;
          try_push(nx, ny, nextk, step + 1, min_dist[nx][ny][nextk]);
        }
      }
      return -1;
    };
    cout << bfs() << endl;
  }
}
/**
 * 
 * #include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    auto maze = vector(n, vector(m, 0));
    int sx, sy;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        cin >> maze[i][j];
        if (maze[i][j] == 2) {
          sx = i;
          sy = j;
        }
      }
    }
    auto bfs = [&]() {
      auto min_dist = vector(n, vector(m, vector(7, INT_MAX)));
      queue<tuple<int, int, int>> q;
      
      auto try_push = [&](int x, int y, int k, int step, int &pre) {
        if (pre <= step) return;
        min_dist[x][y][k] = step;
        q.emplace(x, y, k);
      };
      q.emplace(sx, sy, 6);
      min_dist[sx][sy][6] = 0;
      while (!q.empty()) {
        auto [x, y, k] = q.front();
        q.pop();
        int step = min_dist[x][y][k];
        if (maze[x][y] == 3) return step;
        if (k == 1) continue;
        for (auto [dx, dy] : dir) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (maze[nx][ny] == 0) continue;
          int nextk = k - 1;
          if (maze[nx][ny] == 4) nextk = 6;
          try_push(nx, ny, nextk, step + 1, min_dist[nx][ny][nextk]);
        }
      }
      return -1;
    };
    cout << bfs() << endl;
  }
}
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dir = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    auto maze = vector(n, vector(m, 0));
    int sx, sy;
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        cin >> maze[i][j];
        if (maze[i][j] == 2) {
          sx = i;
          sy = j;
        }
      }
    }
    auto bfs = [&]() {
      auto min_dist = vector(n, vector(m, vector(7, INT_MAX)));
      queue<tuple<int, int, int>> q;
      
      auto try_push = [&](int x, int y, int k, int step, int &pre) {
        if (pre <= step) return;
        min_dist[x][y][k] = step;
        q.emplace(x, y, k);
      };
      q.emplace(sx, sy, 6);
      min_dist[sx][sy][6] = 0;
      while (!q.empty()) {
        auto [x, y, k] = q.front();
        q.pop();
        int step = min_dist[x][y][k];
        if (maze[x][y] == 3) return step;
        if (k == 1) continue;
        for (auto [dx, dy] : dir) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (maze[nx][ny] == 0) continue;
          int nextk = k - 1;
          if (maze[nx][ny] == 4) nextk = 6;
          try_push(nx, ny, nextk, step + 1, min_dist[nx][ny][nextk]);
        }
      }
      return -1;
    };
    cout << bfs() << endl;
  }
}
 */