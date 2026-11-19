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
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int pre = 0, ans = INT_MIN;
  for (int i = 0; i < n; i ++) {
    pre = max(pre + a[i], a[i]);
    ans = max(ans, pre);
  }
  cout << ans << endl;
}