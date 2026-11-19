// 蓝桥杯 24 年 Python B 组省赛 D 题
// 神奇闹钟
// https://www.lanqiao.cn/problems/19730/learning/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int dayInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  auto isLeapYear = [](int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
  };
  auto toTimeStamp = [&](int y, int m, int d, int h, int mm, int s) {
    long long res = 0;
    int secondInDay = 24 * 60 * 60;
    for (int i = 1970; i < y; i ++) {
      res += (365 + isLeapYear(i)) * secondInDay;
    }
    for (int i = 1; i < m; i ++) {
      res += (dayInMonths[i] + (i == 2 && isLeapYear(y))) * secondInDay;
    }
    res += (d - 1) * secondInDay;
    res += h * 60 * 60;
    res += mm * 60;
    res += s;
    return res;
  };
  auto outputTimeStamp = [&](int t) {
    int secondInDay = 24 * 60 * 60;
    int s = t % 60;
    int mm = t % 3600 / 60;
    int h = t % (3600 * 24) / 3600;
    int days = t / secondInDay;
    int y = 1970, m = 1;
    for (; ; ++y) {
      int dayInYear = 365 + isLeapYear(y);
      if (days >= dayInYear) days -= dayInYear;
      else break;
    }
    for (; ; ++m) {
      int dayInMonth = dayInMonths[m] + (m == 2 && isLeapYear(y));
      if (days >= dayInMonth) days -= dayInMonth;
      else break;
    }
    int d = days + 1;
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", y, m, d, h, mm, s);
  };
  int T;
  cin >> T;
  while (T--) {
    int y, m, d, h, mm, s, x;
    scanf("%d-%d-%d %d:%d:%d %d", &y, &m, &d, &h, &mm, &s, &x);
    x *= 60;
    int time = toTimeStamp(y, m, d, h, mm, s) / x * x;
    outputTimeStamp(time);
  }
}