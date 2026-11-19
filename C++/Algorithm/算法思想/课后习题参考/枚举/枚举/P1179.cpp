// 2010 NOIP 普及组
// 数字统计
// https://www.luogu.com.cn/problem/P1179

#include <bits/stdc++.h>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;
  int cnt = 0;
  for (int i = L; i <= R; i++) {
    for (int x = i; x; x /= 10) {
      if (x % 10 == 2) ++cnt;
    }
  }
  cout << cnt << endl;
}