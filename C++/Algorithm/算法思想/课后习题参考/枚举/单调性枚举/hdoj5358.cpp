/**
 * hdoj 在录制课程时，提交有问题
 * 需要有很多的注释，才能提交
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
    while (l == r || (r <= e && !match(l, r - 1))) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    using i64 = long long;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> last(n);
    iota(last.begin(), last.end(), 0);
    // for (int i = 0; i < n; i ++) last[i] = i;
    i64 total = accumulate(a.begin(), a.end(), 0ll);
    i64 ans = 0;
    for (i64 lg = 1, limit = 2; ; lg++, limit <<= 1) {
      i64 sum = 0;
      increaseEnumerate(0, n - 1,
        [&](int l, int r) {
          return sum >= limit;
        },
        [&](int l, int r) {
          sum += a[r];
        },
        [&](int l, int r) {
          sum -= a[l];
        },
        [&](int l, int r) {
          int L = last[l];
          ans += lg * (l + 1) * (r - L + 1) + lg * (L + r + 2) * (r - L + 1) / 2;
          last[l] = r + 1;
        });
      if (limit > total) break;
    }
    cout << ans << endl;
  }
}
/*
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
  // for i : [1, n]
  //   for j : [i, n]
  //     log(sum(i, j)) * (i + j)
  // i * (n - i + 1) + (i + n) * (n - i + 1) / 2
  // log(2^31 - 1) = 31
  // 35
  // [L, R] = lg
  // for lg : [0, 35]
  //   for i : [1, n]      // [L, R]
  //      (i * (R - L + 1) + (L + R) * (R - L + 1) / 2 ) * lg
  // [L, R] sum <= lg
  // 条件: sum > 2^lg   R[i]
  // 找到不符合条件的最大值
  // 条件: sum > lg - 1   R[i-1]
  // [R[i-1] + 1, R[i]]
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    using i64 = long long;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> last(n);
    iota(last.begin(), last.end(), 0);
    // for (int i = 0; i < n; i ++) last[i] = i;
    i64 total = accumulate(a.begin(), a.end(), 0ll);
    i64 ans = 0;
    for (int lg = 1, limit = 2; ; lg++, limit <<= 1) {
      i64 sum = 0;
      increaseEnumerate(0, n - 1,
        [&](int l, int r) {
          return sum >= limit;
        },
        [&](int l, int r) {
          sum += a[r];
        },
        [&](int l, int r) {
          sum -= a[l];
        },
        [&](int l, int r) {
          int L = last[l];
          ans += lg * ((l + 1) * (r - L + 1) + (L + r + 2) * (r - L + 1) / 2);
          last[l] = r + 1;
        });
      if (limit > total) break;
    }
    cout << ans << endl;
  }
}
*/