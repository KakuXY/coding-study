/**
 * 23 Java 国赛 B组 H[二等~一等]
 * 游戏
 * https://www.lanqiao.cn/problems/6251/learning/
 */
#include <bits/stdc++.h>
using namespace std;

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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  mono_deque<int, greater> dec_q;
  mono_deque<int, less> inc_q;
  long long ans = 0;
  for (int i = 0; i < n; i ++) {
    dec_q.push(i, a[i]).shrink_to(i - k);
    inc_q.push(i, a[i]).shrink_to(i - k);
    if (i >= k - 1) {
      ans += dec_q.get_extremum() - inc_q.get_extremum();
    }
  }
  cout << setprecision(2) << fixed;
  cout << ans / (n - k + 1.0) << endl;
}
