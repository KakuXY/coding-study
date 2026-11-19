#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

const double eps = 1e-8;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  auto f = [&](double x) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
  };
  vector<double> ans;
  for (int x = -100; x <= 100; x ++) {
    // 整数
    if (abs(f(x)) < eps) ans.push_back(x); 
  }
  for (int x = -100; x <= 99; x ++) {
    double f1 = f(x);
    double f2 = f(x + 1); // -0.000001
    if (f1 * f2 > -eps) continue;
    double lo = x, hi = x + 1;
    while (lo + eps < hi) {
      double mid = (lo + hi) / 2;
      if (f(mid) * f1 > 0) lo = mid;
      else hi = mid;
    }
    ans.push_back(lo);
  }
  sort(ans.begin(), ans.end());
  cout << fixed << setprecision(2);
  for (auto x : ans) cout << x << ' ';
}