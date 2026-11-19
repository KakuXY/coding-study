// 蓝桥杯 23 年 Python A 组省赛 A 题
// 特殊日期
// https://www.lanqiao.cn/problems/3495/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int dayInMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  auto isLeapYear = [&](int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  };
  int cnt = 1;
  for (int year = 2000; year < 2000000; ++year) {
    for (int month = 1; month <= 12; ++month) {
      int dayInMonth = dayInMonths[month];
      if (isLeapYear(year) && month == 2) ++dayInMonth;
      for (int day = 1; day <= dayInMonth; ++day) {
        if (year % month == 0 && year % day == 0) {
          ++cnt;
        }
      }
    }
  }
  cout << cnt << endl;
}