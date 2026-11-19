#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  partial_sum(a.begin(), a.end(), a.begin(), [](int prev, int cur) {
    return prev ^ cur;
  });
  unordered_map<int, int> cnt;
  cnt[0] = 1;
  for (auto x : a) cnt[x]++;
  long long ans = 0;
  for (auto &[_, v] : cnt) {
    ans += 1ll * v * (v - 1) / 2;
  }
  cout << ans << endl;
}