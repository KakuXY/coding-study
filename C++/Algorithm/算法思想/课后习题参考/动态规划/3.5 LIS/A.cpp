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
  vector<int> dp;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    auto iter = lower_bound(dp.begin(), dp.end(), x);
    if (iter == dp.end()) dp.push_back(x);
    else *iter = x;
  }
  cout << dp.size() << endl;
}