/**
 * 22 c++ 省赛 C 组 H [二等+]
 * 重新排序
 * https://www.lanqiao.cn/problems/2128/learning/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  vector<long long> sum(n + 1);
  partial_sum(a.begin(), a.end(), sum.begin() + 1);
  cin >> m;
  long long total = 0;
  vector<long long> diff(n + 2);
  while (m--) {
    int l, r;
    cin >> l >> r;
    diff[l] ++;
    diff[r+1] --;
    total += sum[r] - sum[l - 1];
  }
  partial_sum(diff.begin(), diff.end(), diff.begin());
  sort(diff.begin(), diff.end(), greater<long long>());
  sort(a.begin(), a.end(), greater<long long>());
  long long ans = 0;
  for (int i = 0; i < n; i ++) {
    ans += a[i] * diff[i];
  }
  cout << ans - total << endl;
}