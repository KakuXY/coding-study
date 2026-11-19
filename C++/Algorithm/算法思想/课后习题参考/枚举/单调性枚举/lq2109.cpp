/**
 * 22 c++ 省赛 B 组 F [二等]
 * 统计子矩阵
 * https://www.lanqiao.cn/problems/2109/learning/
 */
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
    while (r <= e && !match(l, r - 1)) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}
int main() {
  // [(x1, y1), (x2, y2)] <= k
  // [x1, x2] 每一列的和  O(n^2)
  // [y1, y2] [l, r] <= k   O(n)
  // 条件： sum(l, r) > k
  // 不满足的个数
  // O(n^3) 500
  int n, m, k;
  cin >> n >> m >> k;
  auto maze = vector(n, vector<int>(m));
  for (auto &row: maze) {
    for (auto &x : row) cin >> x;
  }
  long long ans = 0; // 500 * 500 * 500 * 500
  for (int x1 = 0; x1 < n; x1 ++) {
    vector<int> sum(m);
    for (int x2 = x1; x2 < n; x2 ++) {
      for (int y = 0; y < m; y++) sum[y] += maze[x2][y];
      int total = 0;
      // for (int l = 0, r = 0; l < m;) {
      //   while (r < m && total <= k) {
      //     total += sum[r++];
      //   }
      //   if (total > k) {
      //     // [l, r - 2]
      //     ans += r - 2 - l + 1;
      //   } else {
      //     // [l, r - 1];
      //     ans += r - 1 - l + 1;
      //   }
      //   total -= sum[l++];
      // }
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
          ans += r - l + 1;
        });
    }
  }
  cout << ans << endl;
}