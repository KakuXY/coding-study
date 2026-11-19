/**
 * 22 国赛 C++ B (6/10)
 * 费用报销
 * https://www.lanqiao.cn/problems/2195/learning
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

const vector<int> month_days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> a(n + 1);
  vector<int> sum(13);
  partial_sum(month_days.begin(), month_days.end(), sum.begin());
  auto get_day = [&](int m, int d) {
    return sum[m - 1] + d - 1;
  };
  for (int i = 1; i <= n; i ++) {
    int m, d;
    cin >> m >> d >> a[i].second;
    a[i].first = get_day(m, d);
  }
  sort(a.begin(), a.end());
  debug(a);
  auto dp = vector(n + 1, bitset<5001>());
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    int last = 0;
    for (int j = i - 1; j >= 0; j --) {
      if (a[j].first + k <= a[i].first) {
        last = j;
        break;
      }
    }
    dp[i] |= dp[last] << a[i].second;
  }
  for (int i = m; i >= 0; i --) {
    if (dp[n][i]) {
      cout << i << '\n';
      break;
    }
  }
}