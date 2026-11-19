/**
 * 24 省赛 c++ C 组 E
 * 回文数组
 * https://www.lanqiao.cn/problems/19715/learning/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> diff(n / 2);
  for (int i = 0; i < n/2; i ++) {
    diff[i] = a[i] - a[n - i - 1];
  }
  n /= 2;
  long long ans = 0;
  for (int i = 0; i < n; i ++) {
    if (i + 1 < n) {
      if (1ll * diff[i] * diff[i + 1] > 0) {
        int min_abs = min(abs(diff[i]), abs(diff[i + 1]));
        ans += min_abs; // operator 2
        if (diff[i] > 0) {
          diff[i] -= min_abs;
          diff[i + 1] -= min_abs;
        } else {
          diff[i] += min_abs;
          diff[i + 1] += min_abs;
        }
      }
    }
    ans += abs(diff[i]); // opeartor 1
  }
  cout << ans << endl;
}