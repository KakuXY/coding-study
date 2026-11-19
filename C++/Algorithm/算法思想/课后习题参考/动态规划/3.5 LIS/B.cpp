#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // lis [x1, x2, x3, x4 ... xn]
  // lds [y1, y2, y3, y4 ... yn]
  // max(xi + yi)
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto getLIS = [&](vector<int> &lis) {
    vector<int> dp;
    for (int i = 0; i < n; i ++) {
      auto iter = lower_bound(dp.begin(), dp.end(), a[i]);
      lis[i] = iter - dp.begin() + 1;
      if (iter == dp.end()) dp.push_back(a[i]);
      else *iter = a[i];
    }
  };
  vector<int> pre(n), suf(n);
  getLIS(pre);
  reverse(a.begin(), a.end());
  getLIS(suf);
  reverse(suf.begin(), suf.end());
  int ans = 0;
  for (int i = 0; i < n; i ++) {
    ans = max(ans, pre[i] + suf[i] - 1);
  }
  cout << n - ans << endl;
}