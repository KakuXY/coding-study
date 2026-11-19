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
  vector<vector<int>> idx(n + 1);
  n *= 5;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    idx[x].push_back(i);
  }
  vector<int> dp;
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    for (int j = 4; j >= 0; j --) {
      int p = idx[x][j];
      auto iter = lower_bound(dp.begin(), dp.end(), p);
      if (iter == dp.end()) dp.push_back(p);
      else *iter = p;
    }
  }
  cout << dp.size() << endl;
}