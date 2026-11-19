#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> maze(n + 1, vector<long long>(n + 1));
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    maze[x - 1][y - 1] += z;
  }
  for (int i = n; i >= 0; i --) {
    for (int j = n; j >= 0; j --) {
      if (i) maze[i][j] -= maze[i - 1][j];
    }
    adjacent_difference(maze[i].begin(), maze[i].end(), maze[i].begin());
  }
  long long sum = 0;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (maze[i][j]) {
        if (i + k > n || j + k > n) {
          cout << -1 << endl;
          return 0;
        }
        sum += abs(maze[i][j]);
        maze[i][j + k] += maze[i][j];
        maze[i+k][j] += maze[i][j];
        maze[i+k][j+k] -= maze[i][j];
        maze[i][j] = 0;
      }
    }
  }
  cout << sum << endl;
}
