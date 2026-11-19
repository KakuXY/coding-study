/**
 * 24 Java 省赛 研究生组 D [三等]
 *    C++ 省赛 C组 F [二等]
 * 商品库存管理
 * https://www.lanqiao.cn/problems/19716/learning/
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  // 0 0 0 0 0 0
  // 1 1 0 0 0 0
  // 1 2 1 1 0 0
  // 1 2 2 2 1 0    m
  // [1 2] 1
  // 1
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> range(m);
  vector<long long> cnt(n + 2);
  for (auto &[f, s] : range) {
    cin >> f >> s;
    cnt[f]++;
    cnt[s + 1]--;
  }
  partial_sum(cnt.begin(), cnt.end(), cnt.begin());
  vector<int> ones(n + 2);
  int zero = 0;
  for (int i = 1; i <= n; i ++) {
    int cur = cnt[i];
    if (cur == 0) zero++;
    if (cur == 1) ones[i] = ones[i - 1] + 1;
    else ones[i] = ones[i - 1];
  }
  // partial_sum(cnt.begin(), cnt.end() - 1, ones.begin(), [&](int prev, int cur) {
  //   if (cur == 0) zero++;
  //   if (cur == 1) return prev + 1;
  //   return prev;
  // });
  for (auto &[f, s] : range) {
    cout << ones[s] - ones[f - 1] + zero << endl;
  }

}
