/**
 * 2024 C++ 省赛 A 组 (5/8)
 * 成绩统计
 * https://www.lanqiao.cn/problems/19705/learning/
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
  int n, k, T;
  cin >> n >> k >> T;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int ans = get_first_match(k, n, [&](int x) {
    vector<int> b(a.begin(), a.begin() + x);
    sort(b.begin(), b.end());
    vector<long long> sum(x + 1), sum2(x + 1);
    for (int i = 1; i <= x; i ++) {
      sum[i] = sum[i - 1] + b[i - 1];
      sum2[i] = sum2[i - 1] + (long long)b[i - 1] * b[i - 1];
    }
    for (int i = k; i <= x; i ++) {
      int l = i - k + 1, r = i;
      double avg = (double)(sum[r] - sum[l - 1]) / k;
      double var = (sum2[r] - sum2[l - 1] - 2 * avg * (sum[r] - sum[l - 1]) + k * avg * avg) / k;
      if (var <= T) return true;
    }
    return false;
  });
  if (ans == n + 1) cout << -1 << endl;
  else cout << ans << endl;
}