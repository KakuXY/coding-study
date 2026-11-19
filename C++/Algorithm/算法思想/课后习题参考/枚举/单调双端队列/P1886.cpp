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
  vector<int> ans_min(n - k + 1), ans_max(n - k + 1);
  mono_deque<int> dec_q; // q[0] > q[1] > q[2]
  mono_deque<int, less> inc_q;
  for (int i = 0; i < n; i ++) {
    inc_q.push(i, a[i]).shrink_to(i - k);
    dec_q.push(i, a[i]).shrink_to(i - k);
    if (i >= k - 1) {
      ans_min[i - k + 1] = inc_q.get_extremum();
      ans_max[i - k + 1] = dec_q.get_extremum();
    }
  }
  // deque<int> inc_q, dec_q;
  // for (int i = 0; i < n; i ++) {
  //   while (!inc_q.empty() && a[ inc_q.back() ] >= a[i]) {
  //     inc_q.pop_back();
  //   }
  //   while (!dec_q.empty() && a[ dec_q.back() ] <= a[i]) {
  //     dec_q.pop_back();
  //   }
  //   while (!inc_q.empty() && inc_q.front() <= i - k) {
  //     inc_q.pop_front();
  //   }
  //   while (!dec_q.empty() && dec_q.front() <= i - k) {
  //     dec_q.pop_front();
  //   }
  //   inc_q.push_back(i);
  //   dec_q.push_back(i);

  //   if (i >= k - 1) {
  //     ans_min[i - k + 1] = a[ inc_q.front() ];
  //     ans_max[i - k + 1] = a[ dec_q.front() ];
  //   }
  // }
  for (auto x : ans_min) cout << x << ' ';
  cout << endl;
  for (auto x : ans_max) cout << x << ' ';
  cout << endl;
}