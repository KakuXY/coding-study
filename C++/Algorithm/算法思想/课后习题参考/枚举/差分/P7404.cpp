/**
 * [JOI 2021]
 * 家庭菜園
 * https://www.luogu.com.cn/problem/P7404
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  // 3 2 2 3 1
  // x -1 0 1 -2  x
  // x [ pos  ][ neg ]
  //     1        -1
  // [1~k] neg [k~n-1] pos, max
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<long long> diff(n + 2);
  adjacent_difference(a.begin(), a.end(), diff.begin() + 1);
  vector<long long> leftSum(n + 2), rightSum(n + 2);
  partial_sum(diff.begin(), diff.end(), leftSum.begin(), [](long long prev, long long cur) {
    if (cur > 0) return prev;
    return prev + (-cur + 1);
  });
  partial_sum(diff.rbegin(), diff.rend(), rightSum.rbegin(), [](long long prev, long long cur) {
    if (cur < 0) return prev;
    return prev + (cur + 1);
  });
  long long ans = LLONG_MAX;
  for (int i = 1; i <= n; i ++) {
    ans = min(ans, max(leftSum[i], rightSum[i + 1]));
  }
  cout << ans << endl;
}

