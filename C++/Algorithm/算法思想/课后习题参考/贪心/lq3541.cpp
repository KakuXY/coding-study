/**
 * 24 省赛 Java B 组 I
 * 最大开支
 * https://www.lanqiao.cn/problems/3541/learning/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<tuple<long long, int, int, int>> pq;
  for (int i = 0; i < m; i ++) {
    int k, b;
    cin >> k >> b;
    pq.emplace(b + k, k, b, 1);
  }
  long long ans = 0;
  while (n --) {
    auto [delta_price, k, b, x] = pq.top();
    pq.pop();
    if (delta_price <= 0) break;
    ans += delta_price;
    long long price = 1ll * (b + k * x) * x;
    long long next_price = 1ll * (b + k * (x + 1)) * (x + 1);
    pq.emplace(next_price - price, k, b, x + 1);
  }
  cout << ans << endl;
}