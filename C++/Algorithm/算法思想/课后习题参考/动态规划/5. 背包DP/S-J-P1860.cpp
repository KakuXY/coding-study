#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, V, K;
  cin >> n >> m >> V >> K;
  vector<int> c(n + 1), g(n + 1);
  for (int i = 1; i <= n; i ++) cin >> c[i] >> g[i];
  vector<pair<int, vector<int>>> magics(m);
  for (auto &[id, magic] : magics) {
    int sz;
    cin >> id >> sz;
    magic.resize(sz);
    for (auto &x : magic) cin >> x;
  }
  
  auto get_min_cost = [&]() {
    vector<vector<int>> min_cost(n + 1, vector<int>(K + 1, INT_MAX / 2));
    vector<vector<int>> bags(2, vector<int>(K + 1));
    for (int i = 1; i <= n; i ++) min_cost[i][0] = c[i];
    for (int k = 1; k <= K; k ++) {
      for (auto &[id, magic] : magics) {
        // 分组背包，使用 k - 1 次魔法，合成所有原材料的最小花费
        fill(bags[1].begin(), bags[1].begin() + k, INT_MAX / 2);
        bags[1][0] = 0;
        for (size_t j = 0; j < magic.size(); j ++) {
          auto &cur = bags[j & 1], &pre = bags[~j & 1];
          fill(cur.begin(), cur.begin() + k, INT_MAX / 2);
          for (int used = 0; used < k; used ++) {
            for (int kk = used; kk < k; kk ++) {
              cur[kk] = min(cur[kk], pre[kk - used] + min_cost[magic[j]][used]);
            }
          }
        }
        min_cost[id][k] = min(min_cost[id][k], bags[~magic.size() & 1][k - 1]);
      }
    }
    return min_cost;
  };

  auto min_cost = get_min_cost();

  debug(min_cost);

  // 二维完全背包, K 次魔方，V 元钱
  vector<vector<int>> dp(K + 1, vector<int>(V + 1));
  for (int i = 1; i <= n; i ++) {
    for (int kk = 0; kk <= K; kk ++) {
      for (int k = kk; k <= K; k ++) {
        for (int v = min_cost[i][kk]; v <= V; v ++) {
          dp[k][v] = max(dp[k][v], dp[k - kk][v - min_cost[i][kk]] + g[i] - min_cost[i][kk]);
        }
      }
    }
  }
  debug(dp);
  cout << dp[K][V] << endl;
}