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
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i ++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<vector<int>> dp(n + 1, vector<int>(3));
  auto check = [&](int x) {
    // [ZZZZZ][FFFFF][ZZZZZ]
    // f(i,0) 没翻面 第 i 个卡片，当前处于第 0 段没翻面，大于 x 的个数
    // f(i,1) 翻面   第 i 个卡片，当前处于第 1 段被翻面，大于 x 的个数
    // f(i,2) 没翻面 第 i 个卡片，当前处于第 2 段没翻面，大于 x 的个数
    for (int i = 1; i <= n; i ++) {
      dp[i][0] = dp[i - 1][0] + (x <= a[i].first);
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (x <= a[i].second);
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + (x <= a[i].first);
    }
    return max({dp[n][0], dp[n][1], dp[n][2]}) >= (n + 1) / 2;
  };
  int lo = 1, hi = 1e9;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) lo = mid + 1;
    else hi = mid - 1;
  }
  cout << lo - 1 << endl;
}
