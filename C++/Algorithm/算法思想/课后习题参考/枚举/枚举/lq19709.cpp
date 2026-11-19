// 蓝桥杯 24 年 C++ B 组省赛 C 题
// 好数
// https://www.lanqiao.cn/problems/19709/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 1; i <= n; i ++) {
    if ([](int x) {
      for (int i = 1; x; i ^= 1, x /= 10) {
        if (x % 2 != i) return false;
      }
      return true;
    }(i)) {
      ++cnt;
    }
  }
  cout << cnt << endl;
}