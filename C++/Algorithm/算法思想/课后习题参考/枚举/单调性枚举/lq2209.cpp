/**
 * 22 C++ 国赛 C 组 F [二等]
 * 近似 GCD
 * https://www.lanqiao.cn/problems/2209/learning/
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
  // 如果有一个元素不是 g 的公倍数，+1
  // 条件: 有两个不是 g 的公倍数
  // [1, 3, 6, 4, 10] g = 3
  // [1, 0, 0, 1, 1] < 2 最大值
  // 不满足条件的个数
  int n, g;
  cin >> n >> g;
  vector<int> a(n);
  for (int &x: a) {
    cin >> x;
    x = x % g != 0;
  }
  int sum = 0;
  long long ans = 0;
  increaseEnumerate(0, n - 1,
    [&](int l, int r) {
      return sum >= 2;
    },
    [&](int l, int r) {
      sum += a[r];
    },
    [&](int l, int r) {
      sum -= a[l];
    },
    [&](int l, int r) {
      // [l, r]
      ans += r - l;
    });
  // for (int l = 0, r = 0; l < n; ) {
  //   while (r < n && sum < 2) {
  //     sum += a[r++];
  //   }
  //   if (sum >= 2) {
  //     // [l, r - 2]  [l+1, r-2];
  //     ans += r - 2 - (l + 1) + 1;
  //   } else {
  //     // [l, r - 2] [l + 1, r - 1];
  //     ans += r - 1 - (l + 1) + 1;
  //   }
  //   sum -= a[l++];
  // }
  cout << ans << endl;
}