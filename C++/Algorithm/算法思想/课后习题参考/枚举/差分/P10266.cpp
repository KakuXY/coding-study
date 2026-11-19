#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  const int N = 3015;
  const int offset = 1005;
  using i64 = long long;
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<i64>> origin(n, vector<i64>(m));
  for (auto &row : origin) {
    for (auto &x : row) cin >> x;
  }
  vector<vector<i64>> diag(N, vector<i64>(N));
  vector<vector<i64>> back_diag(N, vector<i64>(N));
  while (k--) {
    int x, y, p;
    cin >> x >> y >> p;
    x += offset;
    y += offset;
    back_diag[x+1][y] += 2;
    back_diag[x+2][y-1] += 2;
    back_diag[x+1+p][y-p] -= 1;
    back_diag[x+2+p][y-p-1] -= 1;
    back_diag[x+1-p][y+p] -= 1;
    back_diag[x+2-p][y+p-1] -= 1;
    diag[x+1][y+1] -= 2;
    diag[x+2][y+2] -= 2;
    diag[x-p+1][y-p+1] += 1;
    diag[x-p+2][y-p+2] += 1;
    diag[x+p+1][y+p+1] += 1;
    diag[x+p+2][y+p+2] += 1;
  }
  auto diag_sum = [&](auto &diag) {
    for (int i = 1; i < N; i ++) {
      for (int j = 1; j < N; j ++) {
        diag[i][j] += diag[i-1][j-1];
      }
    }
  };
  auto back_diag_sum = [&](auto &back_diag) {
    for (int i = 1; i < N; i ++) {
      for (int j = N - 2; j > 0; j --) {
        back_diag[i][j] += back_diag[i-1][j+1];
      }
    }
  };
  diag_sum(diag);
  diag_sum(diag);
  back_diag_sum(back_diag);
  back_diag_sum(back_diag);
  vector<vector<i64>> total(N, vector<i64>(N));
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < N; j ++) {
      total[i][j] = diag[i][j] + back_diag[i][j];
    }
  }
  for (int i = 1; i < N; i ++) {
    partial_sum(total[i].begin(), total[i].end(), total[i].begin());
    for (int j = 1; j < N; j ++) {
      total[i][j] += total[i - 1][j];
    }
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      origin[i][j] -= total[i + 1 + offset][j + 1 + offset];
      if (origin[i][j] < 0) origin[i][j] = 0;
      cout << origin[i][j] << ' ';
    }
    cout << endl;
  }
}
