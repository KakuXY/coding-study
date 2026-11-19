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
  int n, m;
  cin >> n >> m;
  vector<int> vec(n);
  vector<int> hash(m + 1);
  for (auto &x : vec) cin >> x;
  int cnt = 0;
  pair<int, int> ans = {0, n - 1};
  // for (int l = 0, r = 0; r < n;) {
  //   while (r < n && cnt != m) {
  //     if (hash[vec[r++]]++ == 0) cnt ++;
  //   }
  //   if (cnt == m) {
  //     if (r - l - 1 < ans.second - ans.first) {
  //       ans = {l, r - 1};
  //     }
  //   }
  //   if (hash[vec[l++]]-- == 1) cnt --;
  // }
  increaseEnumerate(0, n - 1,
    [&](int l, int r) {
      return cnt == m;
    },
    [&](int l, int r) {
      if (hash[vec[r]] == 0) cnt ++;
      hash[vec[r]] ++;
    },
    [&](int l, int r) {
      hash[vec[l]] --;
      if (hash[vec[l]] == 0) cnt --;
    },
    [&](int l, int r) {
      if (r + 1 == n) return;
      if (r - l + 1 < ans.second - ans.first) {
        ans = {l, r + 1};
      }
    });
  cout << ans.first + 1 << ' ' << ans.second + 1 << endl;
}