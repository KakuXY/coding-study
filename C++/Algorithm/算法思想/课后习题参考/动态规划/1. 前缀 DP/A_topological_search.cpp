#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;



int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> w(n, vector<int>(n));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j <= i; j ++) {
      cin >> w[i][j];
    }
  }

  vector<vector<int>> indegree(n, vector<int>(n, 0));
  for (int i = 0; i + 1 < n; i ++) {
    for (int j = 0; j <= i; j ++) {
      indegree[i + 1][j] ++;
      indegree[i + 1][j + 1] ++;
    }
  }
  vector<vector<int>> dp(n, vector<int>(n, 0));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j <= i; j ++) {
      if (indegree[i][j] == 0) {
        q.emplace(i, j);
        dp[i][j] = w[i][j];
      }
    }
  }
  pair<int, int> dirs[2] = {{1, 0}, {1, 1}};
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (auto [dx, dy]: dirs) {
      int x = i + dx, y = j + dy;
      if (x == n) continue;
      dp[x][y] = max(dp[x][y], dp[i][j] + w[x][y]);
      indegree[x][y] --;
      if (indegree[x][y] == 0) q.emplace(x, y);
    }
  }
  cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
}