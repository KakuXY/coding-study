#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

/**
 * 很明显的前缀 DP，每个字符都从上一个字符所在的位置转移过来
 * 状态为 dp[i][j]: t 的前 i 个字符，指针位于 s 的 j 位置，的最小移动距离
 * 对于 t[i] 来说，它的字符是确定的，所以 j 所对应的位置也是固定的某些位置，而不是整个 n，平均是 n / 26，不过依旧认为是 O(n)
 * 考虑转移，dp[i][j] -> dp[i + 1][k], j 是 t[i] 的位置，k 是 t[i + 1] 的位置
 * 这样复杂是 O(n * m * n)，超时
 * 考虑优化，从一个字符转移到下一个字符，一定是转移到最近的位置，大于等于 j，或小于 j，不用枚举所有的 k
 * 我们可以用二分预处理出字符a的所有位置到字符b的最近位置【这一步也可以用两个指针从前往后扫，均摊到 O(1), 不过没有二分容易想】
 * 然后转移就可以查表 O(1)
 * 到此，解决此题
 */
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, L;
  cin >> n >> m >> L;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> index(26);
  for (int i = 0; i < n; i ++) {
    index[s[i] - 'a'].push_back(i);
  }
  array<array<vector<vector<pair<int, int>>>, 26>, 26> g;
  for (int u = 0; u < 26; u ++) {
    if (index[u].empty()) continue;
    for (int v = 0; v < 26; v ++) {
      if (index[v].empty()) continue;
      for (auto &p : index[u]) {
        g[u][v].push_back(vector<pair<int, int>>());
        auto &nxt = g[u][v].back();
        if (p > index[v].back()) {
          nxt.push_back({index[v].size() - 1, abs(p - index[v].back())});
        } else if (p <= index[v][0]) {
          nxt.push_back({0, abs(p - index[v][0])});
        } else {
          size_t idx = lower_bound(index[v].begin(), index[v].end(), p) - index[v].begin();
          nxt.push_back({idx, abs(p - index[v][idx])});
          nxt.push_back({idx - 1, abs(p - index[v][idx - 1])});
        }
      }
    }
  }
  vector<vector<int>> dp(2, vector<int>(n + 1));
  int ans = 1;
  for (int i = 0; i < m - 1; i ++) {
    auto &cur = dp[i & 1], &nxt = dp[~i & 1];
    fill(nxt.begin(), nxt.end(), INT_MAX / 2);
    int u = t[i] - 'a', v = t[i + 1] - 'a';
    for (size_t c = 0; c < g[u][v].size(); c ++) {
      for (auto &[n, w] : g[u][v][c]) {
        nxt[n] = min(nxt[n], cur[c] + w);
        if (nxt[n] <= L) ans = i + 2;
      }
    }
    debug(cur);
  }
  cout << ans << endl;
}