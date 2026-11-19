#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

const int maxv = 20001;
template<int theV>
void solve(int n, int V) {
  if (V >= theV) return solve<min(maxv, theV * 2)>(n, V);
  bitset<theV> dp;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    dp |= dp << v;
  }
  for (int i = V; i >= 0; i--) {
    if (dp[i]) {
      cout << V - i << endl;
      break;
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int V, n;
  cin >> V >> n;
  solve<1>(n, V);
}