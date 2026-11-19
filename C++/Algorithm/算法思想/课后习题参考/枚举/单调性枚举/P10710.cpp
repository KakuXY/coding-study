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
  // set    contain(1-n)  最少 max-min
  // 1. 最少 max-min   2. contain(1-n)  二分搜索
  // 1. contain(1-n)  2. 最少 max-min
  // 条件 contain(1-n)
  // 求满足条件的最小值
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> arr;
  arr.reserve(n * m);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      int h;
      cin >> h;
      arr.push_back({h, i});
    }
  }
  sort(arr.begin(), arr.end());
  vector<int> cnt(n);
  int classCnt = 0;
  int ans = INT_MAX;
  increaseEnumerate(0, n * m - 1,
    [&](int l, int r) {
      return classCnt == n;
    },
    [&](int l, int r) {
      if (cnt[arr[r].second]++ == 0) classCnt++;
    },
    [&](int l, int r) {
      if (--cnt[arr[l].second] == 0) classCnt--;
    },
    [&](int l, int r) {
      // [l, r+1]
      if (r + 1 == n * m) return;
      ans = min(ans, arr[r + 1].first - arr[l].first);
    });
  cout << ans << endl;
}