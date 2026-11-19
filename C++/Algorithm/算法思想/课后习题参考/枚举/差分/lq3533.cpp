/**
 * 23 Java 省赛 A 组 D [三等]
 * 棋盘
 * https://www.lanqiao.cn/problems/3533/learning/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  auto maze = vector(n + 2, vector(m + 2, 0));
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    maze[x1][y1] ++;
    maze[x1][y2+1] --;
    maze[x2+1][y1] --;
    maze[x2+1][y2+1] ++;
  }
  for (int i = 1; i <= n; i ++) {
    partial_sum(maze[i].begin(), maze[i].end(), maze[i].begin());
    for (int j = 1; j <= n; j++) {
      maze[i][j] += maze[i - 1][j];
      cout << (maze[i][j] & 1);
    }
    cout << endl;
  }
}