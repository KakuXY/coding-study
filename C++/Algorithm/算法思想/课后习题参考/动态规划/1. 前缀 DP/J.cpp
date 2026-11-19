#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> pos(n);
  for (auto &p : pos) cin >> p;
  vector<int> a(n), b(n);
  for (int i = 0; i < n - 1; i ++) cin >> a[i] >> b[i + 1];
  double in = 1e300;
  double base = pos[0];
  double out = 1e300;
  for (int i = 0; i < n; i ++) {
    if (i) {
      base += pos[i] - pos[i - 1];
      out = in;
    }
    // O -> I, O -> B, B -> I
    double dist = b[i] - a[i];
    double cost = dist > 0 ? dist / 1.3 : dist / -0.7;
    in = min(out + cost, base + a[i] / 0.7);
    base = min(base, out + b[i] / 1.3);
  }
  cout << fixed << setprecision(2) << base << endl;
}