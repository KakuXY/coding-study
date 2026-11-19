/**
 * 23 国赛 Python B组 (2/10)
 * 划分
 * https://www.lanqiao.cn/problems/17143/learning/
 */
#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cout << 12873625444 << endl;
  return 0;
  cin.tie(0)->sync_with_stdio(0);
  const int N = 226924;
  bitset<N + 1> dp;
  dp[0] = 1;
  for (int i = 0; i < 40; i ++) {
    int x;
    cin >> x;
    dp |= dp << x;
  }
  long long ans = 0;
  for (int i = 1; i < N; i ++) {
    if (dp[i]) ans = max(ans, (long long)i * (N - i));
  }
  cout << ans << endl;
}