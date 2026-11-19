// 蓝桥杯 24 年 C++ B 组省赛 B 题
// 小球反弹
// https://www.lanqiao.cn/problems/19732/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int dx = 15, dy = 17;
  int w = 343720 * 2, h = 233333 * 2;
  int dt = lcm(dx, w) / dx;
  for (long long t = dt;; t += dt) {
    if (t * dy % h == 0) {
      cout.precision(2);
      cout << fixed;
      cout << hypot(t * dx, t * dy) << endl;
      break;
    }
  }
}