#include <bits/stdc++.h>
using namespace std;

/**
 * 用单调双端队列解决离线 RMQ
 * 复杂度 O(n + QlogQ + Qlogn)
 */
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  using tiiii = tuple<int, int, int, int>;
  vector<tiiii> q(m);
  for (int i = 0; i < m; i++) {
    auto &[id, l, r, ans] = q[i];
    id = i;
    cin >> l >> r;
    l--, r--;
  }
  ranges::sort(q, [](const tiiii &a, const tiiii &b) {
    return get<2>(a) < get<2>(b);
  });
  deque<int> dec_q;
  int index = 0;
  for (int i = 0; i < n; i++) {
    while (!dec_q.empty() && a[dec_q.back()] <= a[i]) dec_q.pop_back();
    dec_q.push_back(i);
    while (index < m && get<2>(q[index]) == i) {
      auto &[_, l, __, ans] = q[index++];
      ans = a[dec_q[ranges::lower_bound(dec_q, l) - dec_q.begin()]];
    }
  }
  ranges::sort(q);
  for (auto &[id, l, r, ans] : q) cout << ans << '\n';
}