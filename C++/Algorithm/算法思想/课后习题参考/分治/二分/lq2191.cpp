/**
 * 2022 国赛 C++ B 组 (3/10)
 * 卡牌
 * https://www.lanqiao.cn/problems/2191/learning/
 */
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
  int n;
  long long m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  cout << get_first_match(0, 4 * n, [&](int x) {
    // [T, T, T, F, F, F]
    //       this
    long long cnt = 0;
    for (int i = 0; i < n; i ++) {
      if (a[i] + b[i] < x) return true;
      cnt += max(0, x - a[i]);
    }
    return cnt > m;
  }) - 1 << endl;
}