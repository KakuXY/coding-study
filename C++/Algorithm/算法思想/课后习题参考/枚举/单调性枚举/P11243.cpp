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
  // a1 \in R
  // [a1, a2] \in R^2

  //    <<<<
  // 1 2 3 4 5
  // -100 0 100 1000 1001
  // a0 < a4
  // ai aj
  // [i, j]
  //  <<<<<<><<<<<
  // [l, r] 不能出现大于号
  // 条件: 出现大于号    0  -1   sum < 0
  // 不符合条件的区间个数 a
  // 条件：出现小于号    -1  0    sum < 0
  // 不符合条件的区间个数 b
  // 1 < 2 = 2
  // [< =] 2 [=] 1
  //   >   =
  //         [=] 1
  // 条件：出现大于小于号 -1  -1   sum < 0
  // 不符合条件的区间个数 c
  // a + b - 2 * c
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    auto func = [&](int v1, int v2) {
      vector<int> v(128);
      v['<'] = v1;
      v['>'] = v2;
      int sum = 0;
      long long total = 0;
      increaseEnumerate(0, str.size() - 1,
        [&](int l, int r) {
          return sum < 0;
        },
        [&](int l, int r) {
          sum += v[str[r]];
        },
        [&](int l, int r) {
          sum -= v[str[l]];
        },
        [&](int l, int r) {
          total += r - l + 1;
        });
      return total;
    };
    cout << func(0, -1) + func(-1, 0) - func(-1, -1) * 2 << endl;
  }
}