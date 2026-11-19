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
  int m;
  cin >> m; 
  int sum = 0;
  int limit = (m + 1) >> 1;
  // for (int l = 0, r = 0; l <= limit;) {
  //   while (r <= limit && sum < m) sum += r++;
  //   if (sum == m) {
  //     cout << l << ' ' << r - 1 << endl;
  //   }
  //   sum -= l++;
  // }
  increaseEnumerate(0, limit,
    [&](int l, int r) {
      return sum >= m;
    },
    [&](int l, int r) {
      sum += r;
    },
    [&](int l, int r) {
      sum -= l;
    },
    [&](int l, int r) {
      if (sum == m) {
        cout << l << ' ' << r + 1 << endl;
      }
    });
}