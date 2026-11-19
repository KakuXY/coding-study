/**
 * 23 省赛 C++、Java、Python C 组 C
 * 三国游戏
 * https://www.lanqiao.cn/problems/3518/learning/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  using xyz = tuple<int, int, int>;
  vector<xyz> arr(n);
  for (auto &[x, _, __] : arr) cin >> x;
  for (auto &[_, x, __] : arr) cin >> x;
  for (auto &[__, _, x] : arr) cin >> x;
  int ans = -1;
  auto calc = [&]() {
    auto getV = [](xyz &x) {
      auto [a, b, c] = x;
      return a - b - c;
    };
    sort(arr.begin(), arr.end(), [&](xyz &a, xyz &b) {
      return getV(a) > getV(b);
    });
    long long v = 0;
    int cnt = 0;
    for (auto x: arr) {
      v += getV(x);
      cnt += (v > 0);
    }
    if (cnt == 0) return;
    ans = max(ans, cnt);
  };
  calc();
  for (auto &[x, y, z] : arr) swap(x, y);
  calc();
  for (auto &[x, y, z] : arr) swap(x, z);
  calc();
  cout << ans << endl;
}
