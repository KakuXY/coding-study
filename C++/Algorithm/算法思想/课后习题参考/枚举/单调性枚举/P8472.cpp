#include <bits/stdc++.h>
using namespace std;

/**
 * 单调性枚举（区间）模版
 * [s, e] 闭区间
 * match 判断是否满足条件
 * insert 插入右端点
 * remove 删除左端点
 * update 更新答案
 *    [l, r] 是不满足条件的最大区间
 *           如果在 update 时需要使用维护的关键值，因为维护的关键值包含了 r+1，所以需要删除 r+1 进行更新后再加回去
 *    [l, r+1] 是满足条件的最小区间
 *             使用时需要判断 r+1 是否越界
 */
template<typename M, typename I, typename R, typename U>
void increaseEnumerate(int s, int e,
                       const M& match,
                       const I& insert,
                       const R& remove,
                       const U& update) {
  for (int l = s, r = s; l <= e; ) {
    while (l == r || (r <= e && !match(l, r - 1))) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}
int main() {
  // 2
  // 00100
  // 10001
  // K1KKK
  // B  0 1 K+1
  // G  1 0 K+1
  // P  K+1 K+1 0
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> maze(n);
  for (auto &row : maze) cin >> row;
  int ans = 0;
  tuple<char, int, int, int, int> res;
  auto func = [&](int B, int G, int P) {
    vector<int> v(128);
    v['B'] = B;
    v['G'] = G;
    v['P'] = P;
    for (int x1 = 0; x1 < n; x1 ++) {
      vector<int> sum(m);
      for (int x2 = x1; x2 < n; x2 ++) {
        for (int i = 0; i < m; i++) {
          sum[i] += v[maze[x2][i]];
        }
        int total = 0;
        increaseEnumerate(0, m - 1,
          [&](int l, int r) {
            return total > k;
          },
          [&](int l, int r) {
            total += sum[r];
          },
          [&](int l, int r) {
            total -= sum[l];
          },
          [&](int l, int r) {
            int temp = (x2 - x1 + 1) * (r - l + 1);
            if (temp > ans) {
              ans = temp;
              char c = 'P';
              if (B == 0) c = 'B';
              else if (B == 1) c = 'G';
              res = {c, x1, x2, l, r};
            }
          });
      }
    }
  };
  func(0, 1, k + 1);
  func(1, 0, k + 1);
  func(k + 1, k + 1, 0);
  auto [c, x1, x2, y1, y2] = res;
  for (int x = x1; x <= x2; x++) {
    for (int y = y1; y <= y2; y++) {
      maze[x][y] = c;
    }
  }
  cout << ans << endl;
  for (auto &row : maze) cout << row << endl;
}