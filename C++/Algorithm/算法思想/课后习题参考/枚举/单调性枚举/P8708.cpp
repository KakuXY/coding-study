/**
 * 20 c++ 省赛 A 组 H [一等]
 * 整数小拼接
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  //  i  j
  // 12 12 -> 1212  1212
  // 1 2 3 4   <= 33
  // 1 :  12 13 14
  // 2 :  21 23 24
  // 3 :  31 32 / 34
  // 4 :  / 41 42 43
  // ij k[5]
  // i [1]  j[4]
  // i [2]  j[3]
  // i[2] < k[:2]   j [0, 999]
  // i[2] == k[2]   j [0, k[-2:] ]
  // i[2] > k[:2]   j [2]
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  // "12""345" -> "12345"  stoi
  // 12 * 1000 + 345 = 12345
  sort(a.begin(), a.end());
  vector<long long> exp(n, 1);
  for (int i = 0; i < n; i ++) {
    for (int x = a[i]; x ; x /= 10, exp[i] *= 10);
  }
  long long ans = 0;
  for (int l = 0, r = n - 1; r >= 0 && l < n;) {
    if (a[l] * exp[r] + a[r] <= k) {
      // [0, r]
      ans += r + 1;
      if (l <= r) ans --;
      l++;
    } else {
      r--;
    }
  }
  cout << ans << endl;
}