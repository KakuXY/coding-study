// 蓝桥杯 21 年 C++ B 组省赛 B 题
// 卡片
// https://www.lanqiao.cn/problems/1443/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> cards(10, 2021);
  for (int i = 1; ; ++i) {
    if (![&](int x) {
      for (; x; x /= 10) {
        int digit = x % 10;
        if (cards[digit] == 0) return false;
        --cards[digit];
      }
      return true;
    }(i)) {
      cout << i - 1 << endl;
      break;
    }
  }
}