/**
 * 23 python 国赛 B 组 (1/10)
 * 弹珠摆放
 * https://www.lanqiao.cn/problems/17142/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = 10000;
  int target = 20230610;
  vector<int> a(n+1);
  // for (int i = 1; i <= n; i ++) {
  //   a[i] = i;
  // }
  iota(a.begin(), a.end(), 0);
  partial_sum(a.begin(), a.end(), a.begin());
  partial_sum(a.begin(), a.end(), a.begin());
  for (int i = 0; i <= n; i ++) {
    if (a[i] > target) {
      cout << i - 1 << endl;
      break;
    }
  }
} 