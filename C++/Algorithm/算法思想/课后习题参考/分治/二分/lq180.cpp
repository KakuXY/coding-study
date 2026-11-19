/**
 * 2018 C++ 省赛 A 组 (7/10)
 * 三体攻击
 * https://www.lanqiao.cn/problems/180/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

template <typename T, typename M>
T get_first_match(T lo, T hi, M match) {
  while (lo <= hi) {
    T mid = lo + (hi - lo) / 2;
    if (match(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  // m * A * B * C
  // 10^6 * 10^6 = 10^12
  // ans O(log m) * (m + A*B*C)
  // O(logm*(m + A*B*C))  2*10^7
  int A, B, C, m;
  cin >> A >> B >> C >> m;
  auto hp = vector(A + 2, vector(B + 2, vector<int>(C + 2)));
  for (int i = 1; i <= A; i ++) {
    for (int j = 1; j <= B; j ++) {
      for (int k = 1; k <= C; k ++) {
        cin >> hp[i][j][k];
      }
    }
  }
  debug(hp);
  vector<tuple<int, int, int, int, int, int, int>> attacks(m);
  for (auto &[a, b, c, d, e, f, g] : attacks) {
    cin >> a >> b >> c >> d >> e >> f >> g;
  }
  cout << get_first_match(1, m, [&](int x) {
    auto diff = vector(A + 2, vector(B + 2, vector<long long>(C + 2)));
    for (int i = 0; i < x; i ++) {
      auto [la, ra, lb, rb, lc, rc, d] = attacks[i];
      diff[la][lb][lc] += d;
      diff[la][lb][rc+1] -= d;
      diff[la][rb+1][lc] -= d;
      diff[ra+1][lb][lc] -= d;
      diff[la][rb+1][rc+1] += d;
      diff[ra+1][lb][rc+1] += d;
      diff[ra+1][rb+1][lc] += d;
      diff[ra+1][rb+1][rc+1] -= d;
    }
    for (int i = 1; i <= A; i ++) {
      for (int j = 1; j <= B; j ++) {
        for (int k = 1; k <= C; k ++) {
          diff[i][j][k] += diff[i][j][k-1]
                        + diff[i][j-1][k]
                        + diff[i-1][j][k] 
                        - diff[i][j-1][k-1]
                        - diff[i-1][j][k-1]
                        - diff[i-1][j-1][k]
                        + diff[i-1][j-1][k-1];
          if (diff[i][j][k] > hp[i][j][k]) return true;
        }
      }
    }
    return false;
  }) << endl;
}