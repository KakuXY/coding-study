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
  vector<int> dp(10);
  for (int i = 0; i < n; i ++) {
    string str;
    cin >> str;
    int first = str[0] - '0';
    int last = str.back() - '0';
    dp[last] = max(dp[last], dp[first] + 1);
  }
  cout << n - *max_element(dp.begin(), dp.end()) << endl;
}