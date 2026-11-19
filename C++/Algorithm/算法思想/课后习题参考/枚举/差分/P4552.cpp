#include <bits/stdc++.h>
using namespace std;

int main() {
  // [1, 1, 2, 2]
  // [x, 0, 10, 0, x]
  // [1    -1]         0 ~ 10
  //      [-1     1]   10 ~ 0
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  adjacent_difference(a.begin(), a.end(), a.begin());
  a[0] = 0;
  long long pos = 0, neg = 0;
  for (auto &x : a) {
    if (x > 0) pos += x;
    else neg -= x;
  }
  cout << max(pos, neg) << endl;
  cout << abs(pos - neg) + 1 << endl;
}
