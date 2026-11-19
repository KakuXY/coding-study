/**
 * 2022 省赛 C++ C 组 (9/10)
 *          Java 研究生组 (8/10)
 *          Python B 组 (8/10)
 *          Python 研究生组 (7/10)
 * 技能升级
 * https://www.lanqiao.cn/problems/2129/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

template <typename T, typename M>
T get_first_match(T lo, T hi, M match) {
  while (lo <= hi) {
    T mid = lo + (hi - lo) / 2;
    if (match(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> skills(n);
  for (auto &[a, b] : skills) cin >> a >> b;

  int maxSkill = get_first_match(1, 1000000, [&](int x) {
    long long cnt = 0; // 10^11
    for (auto &[a, b] : skills) {
      if (a < x) continue;
      cnt += (a - x) / b + 1;
    }
    return cnt <= m;
  });
  long long sum = 0;
  int totalCnt = 0;
  for (auto &[a, b] : skills) {
    if (a < maxSkill) continue;
    int cnt = (a - maxSkill) / b + 1;
    sum += (long long)(a + (a - (cnt - 1) * b)) * cnt / 2;
    totalCnt += cnt;
  }
  if (totalCnt < m) {
    sum += (long long)(maxSkill - 1) * (m - totalCnt);
  }
  cout << sum << endl;
}