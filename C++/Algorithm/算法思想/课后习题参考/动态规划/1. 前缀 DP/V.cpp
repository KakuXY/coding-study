#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int dp[15][16][16][2][2][256];
using OPT = tuple<int, int, int, int, int, int>;
OPT opt[15][16][16][2][2][256];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, K;
  cin >> n >> m >> K;
  vector<vector<int>> maze(n, vector<int>(m + 1));
  auto sum = maze;
  for (int i = 0; i < n; i ++) {
    for (int j = 1; j <= m; j ++) {
      cin >> maze[i][j];
      sum[i][j] = sum[i][j - 1] + maze[i][j];
    }
  }
  int ans = 0;
  OPT ans_opt = {-1, 0, 0, 0, 0, 0};
  for (int i = 0; i < n - 1; i ++) {
    for (int l = 1; l <= m; l ++) {
      for (int r = l; r <= m; r ++) {
        for (int ld = 0; ld < 2; ld ++) {
          int dl = ld == 0 ? -1 : 1;
          int llimit = ld == 0 ? 0 : m + 1;
          for (int rd = 0; rd < 2; rd ++) {
            int dr = rd == 0 ? -1 : 1;
            int rlimit = rd == 0 ? 0 : m + 1;
            if (r - l + 1 <= K) {
              auto &res = dp[i][l][r][ld][rd][r - l + 1];
              if (res < sum[i][r] - sum[i][l - 1]) {
                res = sum[i][r] - sum[i][l - 1];
                opt[i][l][r][ld][rd][r - l + 1] = {-1, 0, 0, 0, 0, 0};
                if (res > ans) {
                  ans = res;
                  ans_opt = {i, l, r, ld, rd, r - l + 1};
                }
              }
            }
            for (int k = 0; k <= K; k ++) {
              // dp[i][l][r][ld][rd][k] ->
              int v = dp[i][l][r][ld][rd][k];
              for (int nl = l; nl != llimit; nl += dl) {
                for (int nr = r; nr != rlimit; nr += dr) {
                  if (nl > nr) continue;
                  if (nl > r || nr < l) continue;
                  int add = nr - nl + 1;
                  if (k + add > K) continue;
                  for (int nld = ld; nld <= 1; nld ++) { // 0 -> [0, 1],   1 -> [1]
                    for (int nrd = rd; nrd >= 0; nrd --) { // 0 -> [0]   1 -> [0, 1]
                      int &res = dp[i + 1][nl][nr][nld][nrd][k + add];
                      if (res < v + sum[i + 1][nr] - sum[i + 1][nl - 1]) {
                        res = v + sum[i + 1][nr] - sum[i + 1][nl - 1];
                        opt[i + 1][nl][nr][nld][nrd][k + add] = {i, l, r, ld, rd, k};
                        if (res > ans) {
                          ans = res;
                          ans_opt = {i + 1, nl, nr, nld, nrd, k + add};
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "Oil : " << ans << endl;
  auto [i, l, r, ld, rd, k] = ans_opt;
  vector<pair<int, int>> p;
  while (i != -1) {
    // l, r
    for (int j = l; j <= r; j ++) {
      p.emplace_back(i + 1, j);
    }
    tie(i, l, r, ld, rd, k) = opt[i][l][r][ld][rd][k];
  }
  sort(p.begin(), p.end());
  for (auto [x, y]: p) {
    cout << x << ' ' << y << '\n';
  }
}