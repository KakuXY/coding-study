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
  int L, n, m;
  cin >> L >> n >> m;
  vector<int> stones(n);
  for (auto &x : stones) cin >> x;
  stones.push_back(L);
  cout << get_first_match(1, L, [&](int dis) {
    int pos = 0, cnt = 0;
    for (auto stone : stones) {
      if (stone - pos < dis) {
        cnt ++;
      } else {
        pos = stone;
      }
    }
    return cnt > m;
  }) - 1 << endl;
}