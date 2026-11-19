/**
 * 2023 C++ 国赛 A 组 (5/10)
 * 第 K 小的和
 * https://www.lanqiao.cn/problems/17098/learning/
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
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  cout << get_first_match(2, a[n - 1] + b[m - 1], [&](int x) {
    long long cnt = 0;
    for (auto A : a) {
      cnt += upper_bound(b.begin(), b.end(), x - A) - b.begin();
    }
    return cnt >= k;
  }) << endl;
}