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
  vector<int> dp(32);
  while (n --) {
    int x;
    cin >> x;
    int max_v = 0;
    for (int i = 0, y = x; y; y >>= 1, i ++) {
      if (y & 1) max_v = max(max_v, dp[i]);
    }
    for (int i = 0,y = x; y; y >>= 1, i ++) {
      if (y & 1) dp[i] = max_v + 1;
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}