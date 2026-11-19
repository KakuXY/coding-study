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
void increase_enumerate(int s, int e,
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
template <typename T, template<typename> typename Cmp = greater>
class mono_deque : public deque<pair<int, T>> {
 public:
  mono_deque& push(int idx, const T &x) {
    while (!this->empty() && !Cmp<T>()(this->back().second, x)) this->pop_back();
    this->push_back({idx, x});
    return *this;
  }
  mono_deque& shrink_to(int idx) {
    while (!this->empty() && this->front().first <= idx) this->pop_front();
    return *this;
  }
  T get_extremum() { return this->front().second; }
};
int main() {
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  ranges::sort(a);
  int ans = INT_MAX;
  mono_deque<int, less> inc_q;
  mono_deque<int> dec_q; 
  increase_enumerate(0, n - 1,
    [&](int l, int r) {
      return l <= r && dec_q.get_extremum() - inc_q.get_extremum() >= d;
    },
    [&](int l, int r) {
      inc_q.push(r, a[r].second);
      dec_q.push(r, a[r].second);
    },
    [&](int l, int r) {
      inc_q.shrink_to(l);
      dec_q.shrink_to(l);
    },
    [&](int l, int r) {
      if (r + 1 == n) return;
      ans = min(ans, a[r + 1].first - a[l].first);
    });
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}