#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int MAXN = 2e5 + 1;
template<int maxn>
void solve(int n, int k) {
  if (k >= maxn) return solve<min(maxn * 2, MAXN)>(n, k), void();
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i ++) {
    int fa;
    cin >> fa;
    fa --;
    g[fa].push_back(i);
  }
  vector<int> dep(n + 1);
  int mi_dep = INT_MAX;
  auto dfs = [&](auto &self, int u, int d) -> void {
    dep[d] ++;
    for (auto v : g[u]) {
      self(self, v, d + 1);
    }
    if (g[u].empty()) mi_dep = min(mi_dep, d);
  };
  dfs(dfs, 0, 0);
  map<int, int> mp;
  for (int i = 0; i <= mi_dep; i ++) {
    if (dep[i]) mp[dep[i]] ++;
  }
  vector<pair<int, int>> goods(mp.begin(), mp.end());
  bitset<maxn> dp;
  dp[0] = 1;
  int total = 0;
  for (auto [x, y] : goods) {
    total += x * y;
    for (int b = 1; b <= y; y -= b, b *= 2) dp |= dp << (b * x);
    dp |= dp << (y * x);
  }
  for (int i = 0; i <= k; i ++) {
    if (dp[i] && total - i <= n - k) {
      cout << mi_dep + 1 << '\n';
      return;
    }
  }
  cout << mi_dep << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    // cout << "Case #" << cas << ": ";
    int n, k;
    cin >> n >> k;
    solve<1>(n, min(k, n - k));
  }
}