/**
 * 17 省赛 c++ B 组 (10/10)
 * k 倍区间
 * https://www.lanqiao.cn/problems/97/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) cin >> a[i];
  vector<int> s(n + 1);
  for (int i = 1; i <= n; i ++) {
    s[i] = (a[i] + s[i - 1]) % k;
  }
  debug(a);
  debug(s);
  vector<int> cnt(k);
  for (auto &x : s) cnt[x] ++;
  long long ans = 0;
  for (auto &c : cnt) ans += (long long)c * (c - 1) / 2;
  cout << ans << endl;
}