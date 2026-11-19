#include <bits/stdc++.h>
using namespace std;

int main() {
  // vector<int> a(20);
  // int a0 = 10;
  // int d = 3;
  // int n = 10;
  // int s = 5;
  // for (int i = s; i < s + n; i ++) {
  //   a[i] = a0 + (i - s) * d; 
  // }
  // debug(a);
  // adjacent_difference(a.begin(), a.end(), a.begin());
  // debug(a);
  // adjacent_difference(a.begin(), a.end(), a.begin());
  // debug(a);
  // a[l] += s
  // a[l + 1] += d - s;
  // a[r + 1] -= e + d;
  // a[r + 2] += e;
  int n, m;
  cin >> n >> m;
  vector<long long> diff(n + 3);
  while (m--) {
    int l, r, s, e;
    cin >> l >> r >> s >> e;
    int d = (e - s) / (r - l);
    diff[l] += s;
    diff[l + 1] += d - s;
    diff[r + 1] -= e + d;
    diff[r + 2] += e;
  }
  partial_sum(diff.begin(), diff.end(), diff.begin());
  partial_sum(diff.begin(), diff.end(), diff.begin());
  cout << accumulate(diff.begin(), diff.end(), 0ll,
                     [](long long prev, long long cur) { return prev ^ cur; });
  cout << ' ' << *max_element(diff.begin(), diff.end()) << endl;
}
