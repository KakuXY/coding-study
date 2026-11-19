/**
 * 25 C++ A 组(7/8)
 * 地雷阵
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<double, double>> radians;
  for (int i = 0; i < n; i ++) {
    double a, b, r;
    cin >> a >> b >> r;
    double theta = atan2(b, a);
    double len = sqrt(a * a + b * b);
    double delta = asin(r / len);
    radians.emplace_back(theta - delta, theta + delta);
  }
  sort(radians.begin(), radians.end());
  double start = 0, end = 0;
  double sum = 0;
  for (auto &[l, r] : radians) {
    if (l <= end) {
      end = max(end, r);
    } else {
      sum += end - start;
      start = l;
      end = r;
    }
  }
  sum += end - start;
  cout << fixed << setprecision(3) << 1 - sum / atan2(1, 0) << endl;
}