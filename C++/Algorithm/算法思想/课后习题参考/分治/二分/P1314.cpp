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
  long long s;
  cin >> n >> m >> s;
  vector<pair<int, int>> stones(n + 1);
  int maxW = 0;
  for (int i = 1; i <= n; i ++) {
    cin >> stones[i].first >> stones[i].second;
    maxW = max(maxW, stones[i].first);
  }
  vector<pair<int, int>> segs(m);
  for (auto &[l, r] : segs) cin >> l >> r;

  auto calc = [&](int W) {
    vector<int> cnt(n + 1);
    vector<long long> val(n + 1);
    for (int i = 1; i <= n; i ++) {
      cnt[i] = cnt[i - 1] + (stones[i].first >= W);
      val[i] = val[i - 1] + (stones[i].first >= W) * stones[i].second;
    }
    long long total = 0;
    for (auto [l, r] : segs) {
      total += (cnt[r] - cnt[l - 1]) * (val[r] - val[l - 1]);
    }
    return total;
  };
  int minw = get_first_match(0, maxW, [&](int w) {
    return calc(w) < s;
  });
  long long ans = abs(calc(minw) - s);
  if (minw) ans = min(abs(calc(minw - 1)) - s, ans);
  cout << ans << endl;
}