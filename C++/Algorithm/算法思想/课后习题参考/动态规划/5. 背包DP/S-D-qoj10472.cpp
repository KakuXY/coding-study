#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int limit = 1e6;
  vector<int> high{0};
  for (int i = 1; ; i ++) {
    int x = high[i - 1] + i * i;
    if (x > limit) break;
    high.push_back(x);
  }
  vector<int> low{0, 1};
  for (int i = 2; ; i ++) {
    int x = low[i - 2] + i * i;
    if (x > limit) break;
    low.push_back(x);
  }
  vector<tuple<int, int, char>> cands;
  for (size_t i = 2; i < high.size(); i ++) {
    cands.emplace_back(high[i], i, 'H');
  }
  for (size_t i = 3; i < low.size(); i ++) {
    cands.emplace_back(low[i], i, 'L');
  }
  sort(cands.begin(), cands.end());
  int m = cands.size();
  const short inf = m;
  vector<vector<short>> dp(m + 1, vector<short>(limit + 1, inf));
  vector<vector<short>> opt(m + 1, vector<short>(limit + 1, -1));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i ++) {
    int sz = get<0>(cands[i - 1]);
    for (int j = 0; j <= limit; j ++) {
      dp[i][j] = dp[i - 1][j];
      opt[i][j] = -1;
    }
    for (int j = sz; j <= limit; j ++) {
      if (dp[i - 1][j - sz] == inf) continue;
      if (dp[i][j] >= dp[i - 1][j - sz] + 1) {
        dp[i][j] = dp[i - 1][j - sz] + 1;
        opt[i][j] = i - 1;
      }  
    }
  }
  int cas = 1, n;
  while (cin >> n) {
    if (n == 0) break;
    cout << "Case " << cas ++ << ":";
    if (dp[m][n] == inf) cout << " impossible" << endl;
    else {
      int i = m, j = n;
      while (i) {
        int k = opt[i][j];
        if (k != -1) {
          auto [sz, base, type] = cands[k];
          cout << ' ' << base << type;
          j -= sz;
        }
        i -= 1;
      }
      cout << endl;
    }
  }
}