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
  vector<int> idx(n + 1);
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    idx[x] = i;
  }
  vector<int> dp;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    // idx[x]
    auto iter = lower_bound(dp.begin(), dp.end(), idx[x]);
    if (iter == dp.end()) dp.push_back(idx[x]);
    else *iter = idx[x];
  }
  cout << dp.size() << endl;
}