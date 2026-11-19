#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  auto colors = vector(3, vector<int>(n + 2));
  while (m--) {
    int l, r, c;
    cin >> l >> r >> c;
    colors[c - 1][l] ++;
    colors[c - 1][r + 1]--;
  }
  for (auto &color: colors) {
    partial_sum(color.begin(), color.end(), color.begin());
  }
  int ans = 0;
  for (int i = 1; i <= n; i ++) {
    if (colors[0][i] && colors[1][i] && !colors[2][i]) ans++;
  }
  cout << ans << endl;
}
