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
  vector<int> a(n);
  for (auto &x : a)  cin >> x;
  while (m --) {
    int x;
    cin >> x;
    int index = get_first_match(0, n - 1, [&](int index) {
      return a[index] >= x;
    });
    // int index = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (index == n || a[index] != x) cout << -1 << ' ';
    else cout << index + 1 << ' ';
  }
}