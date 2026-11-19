#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  n /= 10;
  using goods = tuple<int, int, int, vector<int>>;
  vector<goods> g(m + 1);
  for (int i = 1; i <= m; i ++) {
    auto &[v, p, q, _] = g[i];
    cin >> v >> p >> q;
    v /= 10;
    get<3>(g[q]).push_back(i);
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= m; i ++) {
    auto &[v, p, q, sub] = g[i];
    if (q) continue;
    if (sub.size()) {
      int sz = sub.size();
      for (int j = n; j >= 0; j --) {
        for (int s = 0; s < (1 << sz); s ++) {
          int vol = v, w = v * p * 10;
          for (int j = 0; j < sz; j ++) {
            if (s >> j & 1) {
              vol += get<0>(g[sub[j]]);
              w += get<0>(g[sub[j]]) * get<1>(g[sub[j]]) * 10;
            }
          }
          if (vol > j) continue;
          dp[j] = max(dp[j], dp[j - vol] + w);
        }
      }
    } else {
      for (int j = n; j >= v; j --) {
        dp[j] = max(dp[j], dp[j - v] + v * p * 10);
      }
    }
  }
  cout << dp[n] << endl;
}