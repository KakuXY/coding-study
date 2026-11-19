/**
 * 24 c++ 省赛 C 组 (7/8)
 * 挖矿
 * https://www.lanqiao.cn/problems/19717/learning/
 * https://www.luogu.com.cn/problem/P10904
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int offset = 1e6 + 1;
  int n, m;
  cin >> n >> m;
  vector<int> sum(offset * 2);
  while (n --) {
    int x;
    cin >> x;
    sum[ x + offset ] ++;
  }
  partial_sum(sum.begin(), sum.end(), sum.begin());
  int ans = 0;
  auto get_sum = [&](int l, int r) {
    return sum[min(r, offset * 2 - 1)] - sum[max(l - 1, 0)];
  };
  for (int step = 0; step * 2 <= m; step ++) {
    int l = -step + offset, r = m - step * 2 + offset;
    ans = max(ans, get_sum(l, r));
    l = -(m - step * 2) + offset, r = step + offset;
    ans = max(ans, get_sum(l, r));
  }
  cout << ans << endl;
}