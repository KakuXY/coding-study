#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n;
    cin >> n;
    multiset<int> dp;
    while (n --) {
      int l, r;
      cin >> l >> r;
      auto iter = dp.upper_bound(r);
      if (iter != dp.end()) dp.erase(iter);
      dp.insert(l);
      cout << dp.size() << ' ';
    }
    cout << endl;
  }
}