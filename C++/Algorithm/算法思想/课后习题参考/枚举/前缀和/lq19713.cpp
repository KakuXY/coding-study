/**
 * 24 c++ 省赛 B 组 H [一等]
 * 拔河
 * https://www.lanqiao.cn/problems/19713/learning/
 * 蓝桥杯 P10429
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  vector<long long> sum(n + 1);
  partial_sum(a.begin(), a.end(), sum.begin() + 1);
  auto ans = LLONG_MAX;
  set<long long> s;
  for (int r = n - 1; r >= 1; r --) {
    // [r+1, x] x /in [r+1, n]
    for (int x = r + 1; x <= n; x++) {
      s.insert(sum[x] - sum[r]);
    }
    for (int l = 1; l <= r; l ++) {
      auto target = sum[r] - sum[l - 1];
      auto iter = s.lower_bound(target);
      if (iter != s.end()) {
        ans = min(ans, *iter - target);
      }
      if (iter != s.begin()) {
        --iter;
        ans = min(ans, target - *iter);
      }
    }
  }
  cout << ans << endl;
}