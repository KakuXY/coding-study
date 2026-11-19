/**
 * 2023 省赛 Python B 组 (4/10)
 * 管道
 * https://www.lanqiao.cn/problems/3544/learning/
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
  int n, len;
  cin >> n >> len;
  using pii = pair<int, int>;
  vector<pii> pipes(n);
  for (auto &[x, s] : pipes) cin >> x >> s;
  sort(pipes.begin(), pipes.end(), [&](pii &a, pii &b) {
    return a.first + a.second < b.first + b.second;
  });
  cout << get_first_match(1, INT_MAX, [&](int time) {
    vector<pair<int, long long>> segs;
    for (auto &[x, s] : pipes) {
      int deltaTime = time - s;
      if (deltaTime < 0) continue;
      segs.emplace_back(x - deltaTime, x + deltaTime);
      // (x + s) - time
    }
    long long maxRight = 0;
    for (auto &[l, r] : segs) {
      if (l <= maxRight + 1) {
        maxRight = max(maxRight, r);
      } else {
        return false;
      }
    }
    return maxRight >= len;
  }) << endl;
}