/**
 * 22 省赛 c++ A 组 F [二等]
 *        Java A 组 G [二等+]
 *        Java C 组 H [二等+]
 *        Python A 组 I [一等]
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

// 2x 个小青蛙, y, 能不能调到对岸
// 1 0 1 0
// 2, y = 1
// y = 2
// y = 3
// y = 4
// first [0, y] >= 2x
// [1, y+1] >= 2x
// [l, l+y] >= 2x
// y    [i, i+y] >= 2x   二分
// [l, r] < 2x
// 条件 [l, r] >= 2x
// 不满足条件的最大值 +1
int main() {
  int n, x;
  cin >> n >> x;
  n--;
  vector<int> arr(n);
  for (auto &y: arr) cin >> y;
  x <<= 1;
  int sum = 0;
  int ans = 0;
  increaseEnumerate(0, n - 1,
    [&](int l, int r) {
      return sum >= x;
    },
    [&](int l, int r) {
      sum += arr[r];
    },
    [&](int l, int r) {
      sum -= arr[l];
    },
    [&](int l, int r) {
      // [l, r]
      ans = max(ans, r - l + 1);
    });
  cout << ans + 1 << endl;
}