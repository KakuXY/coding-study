#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

/**
 * 和之前一题《数组个数》比较像，要确认第 i 行的得分，我们需要知道 i-1,i,i+1 的翻转情况
 * 因此，记录当前行和上一行的翻转情况，就可以转移，注意第一行和最后一行，其实就算上下、左右循环也一样能做
 * f(i, b, a) 表示第 i 行翻转情况为 a, i-1 行翻转情况为 b，前 i-1 行的最大得分
 * f(i - 1, c, b) + score(i - 1, a, b, c) -> f(i, a, b)
 * 计算得分可以写个函数，避免写一大堆 if else
 */
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> strs(n);
  for (auto &s : strs) cin >> s;
  vector<vector<int>> board(n, vector<int>(m));
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      board[i][j] = strs[i][j] - '0';
    }
  }
  pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  auto score = [&](int i, int a, int b, int c) {
    // 计算第 i 行分数
    // a 是 i + 1 的翻转情况
    // b 是 i 的翻转情况
    // c 是 i - 1 的翻转情况
    auto get = [&](int x, int y) {
      if (x == i) return board[x][y] ^ b;
      if (x == i + 1) return board[x][y] ^ a;
      return board[x][y] ^ c;
    };
    int res = 0;
    for (int j = 0; j < m; j ++) {
      int same = 0;
      int center = get(i, j);
      for (auto [dx, dy] : dir) {
        int x = i + dx, y = j + dy;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (get(x, y) == center) same ++;
      }
      res += same * same;
    }
    return res;
  };
  vector<array<array<int, 2>, 2>> dp(2);
  // dp[i][b][a] 第 i 行(滚动)翻转情况为 a, i - 1 行翻转情况为 b，前 i - 1 行的最大分数
  for (int b = 0; b < 2; b ++) {
    for (int a = 0; a < 2; a ++) {
      // 初始化状态第一行，计算第 0 行的分数
      dp[1][b][a] = score(0, a, b, 0);
    }
  }
  for (int i = 2; i < n; i ++) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    for (int a = 0; a < 2; a ++) {
      for (int b = 0; b < 2; b ++) {
        cur[b][a] = 0;
        for (int c = 0; c < 2; c ++) {
          cur[b][a] = max(cur[b][a], pre[c][b] + score(i - 1, a, b, c));
        }
      }
    }
  }
  int ans = 0;
  for (int a = 0; a < 2; a ++) {
    for (int b = 0; b < 2; b ++) {
      ans = max(ans, dp[~n & 1][b][a] + score(n - 1, 0, a, b));
    }
  }
  cout << ans << endl;
}