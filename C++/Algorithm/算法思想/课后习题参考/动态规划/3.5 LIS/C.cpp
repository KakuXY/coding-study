#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vector<int> a;
  int x;
  while (cin >> x) {
    a.push_back(x);
  }
  vector<int> dp;
  for (auto x : a) {
    auto iter = upper_bound(dp.begin(), dp.end(), -x);
    if (iter == dp.end()) dp.push_back(-x);
    else *iter = -x;
  }
  cout << dp.size() << endl;
  dp.clear();
  for (auto x : a) {
    auto iter = lower_bound(dp.begin(), dp.end(), x);
    if (iter == dp.end()) dp.push_back(x);
    else *iter = x;
  }
  cout << dp.size() << endl;
}