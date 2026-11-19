/**
 * 23 省赛 C++ B组 (4/10)
 * 飞机降落
 * https://www.lanqiao.cn/problems/3511/learning/
 * https://www.luogu.com.cn/problem/P9241
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> planes(n);
    for (auto &[t, d, l] : planes) cin >> t >> d >> l;
    // auto can_land = [&]() {
    //   int last = 0;
    //   for (auto &[t, d, l] : planes) {
    //     if (t + d < last) return false;
    //     last = max(last, t) + l;
    //   }
    //   return true;
    // };
    // auto check = [&]() {
    //   sort(planes.begin(), planes.end());
    //   do {
    //     if (can_land()) return true;
    //   } while (next_permutation(planes.begin(), planes.end()));
    //   return false;
    // };
    vector<int> used(n);
    auto traceback = [&](auto &self, int cnt, int last) {
      if (cnt == n) return true;
      for (int i = 0; i < n; i ++) {
        if (used[i]) continue;
        auto [t, d, l] = planes[i];
        if (t + d < last) continue;
        used[i] = true;
        if (self(self, cnt + 1, max(last, t) + l)) return true;
        used[i] = false;
      }
      return false;
    };
    cout << (traceback(traceback, 0, 0) ? "YES" : "NO") << endl;
    
  }
}