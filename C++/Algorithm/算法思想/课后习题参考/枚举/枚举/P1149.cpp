// 2008 NOIP 提高组
// 火柴棒等式
// https://www.luogu.com.cn/problem/P1149

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> digits = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (int n = 0; n <= 24; n++) {
    int ans = 0;
    auto cnt = [&](int x) {
      if (x == 0) return digits[0];
      int res = 0;
      for (int y = x; y; y /= 10) {
        res += digits[y % 10];
      }
      return res;
    };
    for (int a = 0; a <= 1111; a ++) {
      for (int b = 0; b <= 1111; b ++) {
        int c = a + b;
        if (cnt(a) + cnt(b) + cnt(c) == n - 4) {
          ans ++;
        }
      }
    }
    cout << ans << ", ";
  }
  vector<int> ans = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 8, 9, 6, 9, 29, 39, 38, 65, 88, 128};
  int n;
  cin >> n;
  cout << ans[n] << endl;
}