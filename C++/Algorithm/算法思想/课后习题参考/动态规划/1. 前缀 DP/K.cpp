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
  string s, t;
  cin >> s >> t;
  vector<array<int, 3>> dp(2);
  const int inf = INT_MAX / 2;
  dp[n & 1] = {inf, 0, inf};
  for (int i = n - 1; i >= 0; i --) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    for (int c = 0; c < 3; c ++) {
      int target = t[i] - '0' + (c - 1) * 10;
      cur[c] = min({
        pre[0] + abs(target - (s[i] - '0' - 1)),
        pre[1] + abs(target - (s[i] - '0')),
        pre[2] + abs(target - (s[i] - '0' + 1)),
      });
    }
  }
  cout << *min_element(dp[0].begin(), dp[0].end()) << endl;
}