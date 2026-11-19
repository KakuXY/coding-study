/**
 * 18 省赛 c++ B 组 H [二等+]
 * 日志统计
 * https://www.lanqiao.cn/problems/179/learning/
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
  // 条件: t[r] - t[l] >= d
  // 不符合条件的区间, 是否有 >= k
  int n, d, k;
  cin >> n >> d >> k;
  auto logs = vector<pair<int, int>>(n);
  for (auto &[t, id]: logs) cin >> t >> id;
  sort(logs.begin(), logs.end());
  vector<int> cnt(100001);
  set<int> ans;
  // for (int l = 0, r = 0; r < n;) {
  //   while (r < n && logs[r].first - logs[l].first < d) {
  //     int id = logs[r++].second;
  //     cnt[id]++;
  //     if (cnt[id] == k) ans.insert(id);
  //   }
  //   cnt[logs[l++].second]--;
  // }
  increaseEnumerate(0, n - 1,
    [&](int l, int r) {
      return logs[r].first - logs[l].first >= d;
    },
    [&](int l, int r) {
      cnt[ logs[r].second ]++;
    },
    [&](int l, int r) {
      cnt[ logs[l].second ]--;
    },
    [&](int l, int r) {
      // [l:0~n-1, r]
      if (cnt[ logs[l].second ] >= k) ans.insert(logs[l].second);
    });
  for (auto x: ans) cout << x << endl;
}