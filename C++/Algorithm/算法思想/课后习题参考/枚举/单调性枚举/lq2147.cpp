/**
 * 22 Java 省赛 B 组 F [二等]
 * 最大子矩阵
 * https://www.lanqiao.cn/problems/2147/learning/
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
  // [max - min] 越大
  // 条件：[l, r] > limit
  // 寻找不满足条件的最大值
  // insert, erase, max, min
  // multiset       rbegin  begin
  int n, m, limit;
  cin >> n >> m;
  auto maze = vector(n, vector<int>(m));
  for (auto &row : maze) {
    for (auto &x : row) cin >> x;
  }
  cin >> limit;
  int ans = 0;
  for (int x1 = 0; x1 < n; x1 ++) {
    vector<int> mmin(m, INT_MAX);
    vector<int> mmax(m, INT_MIN);
    // [x1 ~ x2][y] max, min
    for (int x2 = x1; x2 < n; x2 ++) {
      for (int i = 0; i < m; i ++) {
        mmin[i] = min(mmin[i], maze[x2][i]);
        mmax[i] = max(mmax[i], maze[x2][i]);
      }
      multiset<int> s;
      increaseEnumerate(0, m - 1,
        [&](int l, int r) {
          return !s.empty() && *s.rbegin() - *s.begin() > limit;
        },
        [&](int l, int r) {
          s.insert(mmin[r]);
          s.insert(mmax[r]);
        },
        [&](int l, int r) {
          s.erase(s.find(mmin[l]));
          s.erase(s.find(mmax[l]));
        },
        [&](int l, int r) {
          ans = max(ans, (x2 - x1 + 1) * (r - l + 1));
        });
      // for (int l = 0, r = 0; l < m;) {
      //   while (r < m && (s.empty() || *s.rbegin() - *s.begin() <= limit)) {
      //     s.insert(mmin[r]);
      //     s.insert(mmax[r++]);
      //   }
      //   if (!(s.empty() || *s.rbegin() - *s.begin() <= limit)) {
      //     // [l, r - 2]
      //     ans = max(ans, (x2 - x1 + 1) * (r - l - 1));
      //   } else {
      //     ans = max(ans, (x2 - x1 + 1) * (r - l));
      //   }
      //   s.erase(s.find(mmin[l]));
      //   s.erase(s.find(mmax[l++]));
      // }
    }
  }
  cout << ans << endl;
}