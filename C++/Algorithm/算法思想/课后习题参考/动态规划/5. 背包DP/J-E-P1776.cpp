#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

void solve() {
  int n, V;
  cin >> n >> V;
  vector<int> dp(V + 1);
  for (int i = 1; i <= n; i ++) {
    int v, w, k;
    cin >> w >> v >> k;
    for (int c = 0; c < v; c ++) {
      deque<pair<int, int>> q;
      q.emplace_back(0, dp[c]);
      for (int j = 1; j * v + c <= V; j ++) {
        int val = dp[j * v + c] - j * w;
        while (!q.empty() && q.back().second <= val) q.pop_back();
        q.emplace_back(j, val);
        while (q.front().first < j - k) q.pop_front();
        dp[j * v + c] = max(dp[j * v + c], q.front().second + j * w);
      }
    }
  }
  cout << dp[V] << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    solve();
  }
}