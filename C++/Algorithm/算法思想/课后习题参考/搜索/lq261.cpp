/**
 * 13 国赛 C++
 * 九宫重排
 * https://www.lanqiao.cn/problems/261/learning
 * https://www.luogu.com.cn/problem/P1379
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

vector<pair<int, int>> dirs = {
  {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s, e;
  cin >> s >> e;
  // e = "123804765";
  unordered_set<string> visited;
  visited.insert(s);
  queue<tuple<string, int, int, int>> que;
  int index = s.find('.');
  que.emplace(s, 0, index / 3, index % 3);
  while (!que.empty()) {
    auto [cur, step, x, y] = que.front();
    que.pop();
    if (cur == e) {
      cout << step << endl;
      return 0;
    }
    for (auto [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
      swap(cur[x * 3 + y], cur[nx * 3 + ny]);
      if (visited.find(cur) == visited.end()) {
        visited.insert(cur);
        que.emplace(cur, step + 1, nx, ny);
      }
      swap(cur[x * 3 + y], cur[nx * 3 + ny]);
    }
  }
  cout << -1 << endl;
}