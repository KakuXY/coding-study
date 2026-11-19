// 蓝桥杯 23 年 C++ A 组省赛 A 题
// 幸运数
// https://www.lanqiao.cn/problems/3491/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int cnt = 0;
  for (int i = 1; i <= 100000000; i ++) {
    int digitCnt = [](int x) {
      int cnt = 0;
      for (; x; x /= 10) ++cnt;
      return cnt;
    }(i);
    if (digitCnt % 2) continue;
    if ([](int x, int cnt) {
      int half = cnt / 2;
      int sumLeft = 0, sumRight = 0;
      for (int i = 0; i < cnt; ++i, x /= 10) {
        if (i < half) sumLeft += x % 10;
        else sumRight += x % 10;
      }
      return sumLeft == sumRight;
    }(i, digitCnt)) ++cnt;
  }
  cout << cnt << endl;
  // cout << 4430091 << endl;
}