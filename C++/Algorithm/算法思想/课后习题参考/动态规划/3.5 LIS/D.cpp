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
  vector<int> pos(m);
  for (auto &x : pos) cin >> x;
  vector<int> cnt(n + 2);
  for (int i = 1; i <= n; i ++) cin >> cnt[i];
  cnt[0] = 0, cnt[n + 1] = INT_MAX;
  pos.push_back(0);
  pos.push_back(n + 1);
  sort(pos.begin(), pos.end());
  for (int i = 2; i <= m; i ++) {
    if (cnt[ pos[i - 1] ] >= cnt[ pos[i] ]) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  int total = 0;
  for (int i = 1; i <= m + 1; i ++) {
    int start = pos[i - 1], end = pos[i];
    vector<int> dp;
    for (int j = start + 1; j < end; j ++) {
      if (cnt[j] <= cnt[start] || cnt[j] >= cnt[end]) continue;
      auto iter = lower_bound(dp.begin(), dp.end(), cnt[j]);
      if (iter == dp.end()) dp.push_back(cnt[j]);
      else *iter = cnt[j];
    }
    total += dp.size();
  }
  cout << total + m << endl;
}