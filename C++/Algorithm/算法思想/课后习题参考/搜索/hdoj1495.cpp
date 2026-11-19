#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int s, n, m;
  while (cin >> s >> n >> m) {
    if (s == 0 && n == 0 && m == 0) break;
    auto min_step = vector(s + 1, vector(n + 1, INT_MAX));
    queue<tuple<int, int, int>> q;
    q.emplace(s, 0, 0);
    min_step[s][0] = 0;
    vector<int> limit = {s, n, m};
    [&]() {
      while (!q.empty()) {
        auto [a, b, c] = q.front();
        debug(q.front());
        q.pop();
        int step = min_step[a][b];
        if ((a == b && c == 0) ||
            (a == c && b == 0) ||
            (b == c && a == 0)) {
              cout << step << endl;
              return;
            }
        for (int i = 0; i < 3; i ++) {
          for (int j = 0; j < 3; j ++) {
            if (i == j) continue;
            // i -> j
            vector<int> cur = {a, b, c};
            cur[j] = min(limit[j], cur[j] + cur[i]);
            cur[i] = s - cur[j] - cur[3-i-j];
            debug(cur);
            if (min_step[ cur[0] ][ cur[1] ] <= step + 1) continue;
            min_step[ cur[0] ][ cur[1] ] = step + 1;
            q.emplace(cur[0], cur[1], cur[2]);
          }
        }
        // a->b
        // a->c
        // b->c
        // b->a

      }
      cout << "NO" << endl;
    }();
  }
}