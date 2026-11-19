#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

template <typename T, typename M>
T get_first_match(T lo, T hi, M match) {
  while (lo <= hi) {
    T mid = lo + (hi - lo) / 2;
    if (match(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> rooms(n + 1);
  for (int i = 1; i <= n; i ++) cin >> rooms[i];
  vector<tuple<int, int, int>> orders(m);
  for (auto &[d, s, t] : orders) cin >> d >> s >> t;
  int firstCantFit = get_first_match(1, m, [&](int day) {
    // 无法满足的订单
    vector<long long> diff(n + 2);
    for (int i = 0; i < day; i ++) {
      auto [d, s, t] = orders[i];
      diff[s] += d;
      diff[t + 1] -= d;
    }
    for (int i = 1; i <= n; i ++) {
      diff[i] += diff[i - 1];
      if (diff[i] > rooms[i]) return true;
    }
    return false;
  });
  if (firstCantFit == m + 1) cout << 0 << endl;
  else cout << -1 << endl << firstCantFit << endl;
}