#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  while (cin >> n, n) {
    vector<int> limit(n);
    for (auto &x : limit) cin >> x;
    
    vector<unordered_map<vector<int>, i64, decltype([](auto &vec) {
      size_t res = 0;
      for (auto x : vec) res = res * 31 + x;
      return res;
    })>> dp(2);
    
    dp[0][vector<int>(n, 0)] = 1;
    int total = accumulate(limit.begin(), limit.end(), 0);
    for (int step = 0; step < total; step ++) {
      auto &cur = dp[step & 1], &nxt = dp[~step & 1];
      nxt.clear();
      for (auto &[arrange, val] : cur) {
        for (int i = 0; i < n; i ++) {
          if (arrange[i] == limit[i]) continue;
          if (i && arrange[i] == arrange[i - 1]) continue;
          auto nxt_arrange = arrange;
          nxt_arrange[i] ++;
          nxt[nxt_arrange] += val;
        }
      }
    }
    cout << dp[total & 1][limit] << endl;
  }
}