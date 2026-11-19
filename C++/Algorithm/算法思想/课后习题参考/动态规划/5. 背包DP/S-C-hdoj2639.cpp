#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n, m;
    size_t k;
    cin >> n >> m >> k;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i ++) cin >> w[i];
    for (int i = 0; i < n; i ++) cin >> v[i];

    vector<vector<int>> dp(m + 1);
    dp[0].push_back(0);
    auto merge = [&](vector<int> &a, vector<int> &b, int w) {
      vector<int> c;
      size_t i = 0, j = 0;
      while (i < a.size() && j < b.size() && c.size() < k) {
        if (a[i] == b[j] + w) {
          c.push_back(a[i++]);
          j ++;
        }
        else if (a[i] > b[j] + w) c.push_back(a[i ++]);
        else c.push_back(b[j ++] + w);
      }
      while (i < a.size() && c.size() < k) c.push_back(a[i ++]);
      while (j < b.size() && c.size() < k) c.push_back(b[j ++] + w);
      a = c;
    };
    for (int i = 0; i < n; i ++) {
      for (int j = m; j >= v[i]; j --) {
        merge(dp[j], dp[j - v[i]], w[i]);
      }
    }
    vector<int> ans;
    for (int i = 0; i <= m; i ++) {
      merge(ans, dp[i], 0);
    }
    if (ans.size() < k) cout << "0\n";
    else cout << ans[k - 1] << '\n';
  }
}