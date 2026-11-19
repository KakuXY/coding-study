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
  vector<int> rotate;
  int f = 0, b = 0;
  while (n --) {
    string op;
    int num;
    cin >> op >> num;
    if (op[0] == 'f') f += num;
    else if (op[0] == 'b') b += num;
    else if (op[0] == 'l') rotate.push_back(num);
    else rotate.push_back(-num);
  }
  vector<vector<int>> dp(2, vector<int>(360));
  dp[1][0] = 1;
  for (int i = 0; i < (int)rotate.size(); i ++) {
    auto &cur = dp[i & 1], &pre = dp[~i & 1];
    int d = rotate[i];
    d = (d % 360 + 360) % 360;
    for (int j = 0; j < 360; j ++) {
      cur[j] |= pre[j];
      cur[(j + d) % 360] |= pre[j];
    }
  }
  auto &cur = dp[~rotate.size() & 1];
  double ans = 0;
  for (int i = 0; i < 360; i ++) {
    if (cur[i]) {
      ans = max(ans, sqrt(f * f + b * b - 2 * f * b * cos(i * acos(-1) / 180)));
    }
  }
  cout << fixed << setprecision(6) << ans << '\n';
}