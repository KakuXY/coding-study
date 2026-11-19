/**
 * 23 c++ 国赛 B 组 (7/10)
 * 抓娃娃
 * https://www.lanqiao.cn/problems/17110/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> pos(2e6+1);
  while (n --) {
    int l, r;
    cin >> l >> r;
    pos[l + r] ++;
  }
  partial_sum(pos.begin(), pos.end(), pos.begin());
  while (m --) {
    int l, r;
    cin >> l >> r;
    cout << pos[r * 2] - pos[l * 2 - 1] << endl;
  }
}