/**
 * 23 国赛 Python B组 (9/10)
 * 贸易航线
 * https://www.lanqiao.cn/problems/17149/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  auto goods = vector(n, vector(m, 0));
  for (auto &row : goods) for (auto &cell : row) cin >> cell;
  vector<vector<pair<int, int>>> nexts(n);
  for (int i = 0; i < n - 1; i ++) {
    nexts[i].emplace_back(i + 1, 0);
  }
  for (int j = 0; j < m; j ++) {
    int last = 0;
    while (last < n && goods[last][j] == -1) last ++;
    for (int i = last + 1; i < n; i ++) {
      while (i < n && goods[i][j] == -1) i++;
      if (i == n) break;
      if (goods[i][j] > goods[last][j]) {
        nexts[last].emplace_back(i, goods[i][j] - goods[last][j]);
      }
      last = i;
    }
  }
  vector<long long> dp(n, 0);
  for (int i = 0; i < n; i ++) {
    for (auto [v, w] : nexts[i]) {
      dp[v] = max(dp[v], dp[i] + w);
    }
  }
  cout << *max_element(dp.begin(), dp.end()) * k << '\n';
}