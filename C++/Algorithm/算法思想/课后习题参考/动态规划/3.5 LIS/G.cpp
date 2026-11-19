#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> suf(n);
  vector<int> dp;
  for (int i = n - 1; i >= 0; i --) {
    auto iter = upper_bound(dp.begin(), dp.end(), -a[i]);
    suf[i] = iter - dp.begin() + 1;
    if (iter == dp.end()) dp.push_back(-a[i]);
    else *iter = -a[i];
  }
  // suf[i]: 从后往前到 i 最长不上升子序列
  // 从 i 开始往后的最长不下降子序列
  dp.clear();
  int ans = 0;
  for (int i = k; i < n; i ++) {
    auto pos = upper_bound(dp.begin(), dp.end(), a[i]);
    ans = max(ans, int(pos - dp.begin()) + k + suf[i]);

    auto iter = upper_bound(dp.begin(), dp.end(), a[i - k]);
    if (iter == dp.end()) dp.push_back(a[i - k]);
    else *iter = a[i - k];
  }
  cout << ans << endl;
}