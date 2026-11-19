#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  n --;
  vector<long long> sum(n + 1);
  for (int i = 1; i <= n; i ++) {
    long long x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
  }
  long long ans = 0;
  for (int i = k; i <= n; i ++) {
    ans = max(ans, sum[i] - sum[i - k]);
  }
  cout << sum[n] - ans << endl;
}