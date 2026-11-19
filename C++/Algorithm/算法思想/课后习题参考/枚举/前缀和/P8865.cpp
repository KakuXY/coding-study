/**
 * NOIP 2022
 * 种花
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  // brute O(n^2)
  // for x2 O(n)
  //    for y0 O(n)
  //       sum_right[x1][y0] *
  //       sum_right[x2][y0]
  // s[x2][y0] * s[x2-2][y0] +
  // s[x2][y0] * s[x2-3][y0] +
  // s[x2][y0] * s[x2-4][y0] +
  //          maze[x2-i] = 1
  // sum_right (x, y) 往右有多少个连续的0
  // sum_up (x, y) 往上直到遇到 1 或边界的 sun_right 的总和
  // sum_down (x, y) 往下有多少个连续的0
  // x2, y0
  // C = (sum_right(x2, y0) - 1) * sum_up(x2 - 2, y0)
  // F = C * sum_doown(x2, y0)
  const int mod = 998244353;
  int T, id;
  cin >> T >> id;
  while (T--) {
    int n, m, c, f;
    cin >> n >> m >> c >> f;
    vector<string> maze(n);
    for (auto &x : maze) cin >> x;
    auto sum_right = vector(n, vector(m + 1, 0));
    for (int i = 0; i < n; i ++) {
      for (int j = m - 1; j >= 0; j --) {
        if (maze[i][j] == '0') {
          sum_right[i][j] = sum_right[i][j + 1] + 1;
        }
      }
    }
    // debug(sum_right);
    auto sum_up = vector(n, vector(m, 0));
    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < m; j ++) {
        if (maze[i][j] == '0') {
          if (i) sum_up[i][j] = sum_up[i - 1][j];
          sum_up[i][j] += sum_right[i][j] - 1;
        }
      }
    }
    // debug(sum_up);
    auto sum_down = vector(n + 1, vector(m, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (maze[i][j] == '0') {
          sum_down[i][j] = sum_down[i+1][j] + 1;
        }
      }
    }
    // debug(sum_down);
    long long cntc = 0, cntf = 0;
    for (int x = 2; x < n; x++) {
      for (int y = 0; y < m - 1; y++) {
        if (maze[x][y] == '1' || maze[x-1][y] == '1') continue;
        cntc += sum_up[x - 2][y] * (sum_right[x][y] - 1); // < 2^30
        cntf += 1ll * sum_up[x - 2][y] * (sum_right[x][y] - 1) * (sum_down[x][y] - 1); // ~ 2^40
        // dout << cntc << cntf << x << y;
        cntc %= mod;
        cntf %= mod;
      }
    }
    cout << cntc * c << ' ' << cntf * f << endl;
  }
}