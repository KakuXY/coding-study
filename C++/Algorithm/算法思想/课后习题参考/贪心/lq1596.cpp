/**
 * 21 国赛 C++ C组 (9/10)
 * 巧克力
 * https://www.lanqiao.cn/problems/1596/learning/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
               // deadline, price, cnt
  vector<tuple<int, int, int>> chos(n);
  for (auto &[d, p, c] : chos) cin >> p >> d >> c;
  sort(chos.begin(), chos.end());
  using pii = pair<int, int>; // price, cnt
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  long long ans = 0;
  int index = n - 1;
  for (; x > 0; x--) {
    while (index >= 0) {
      auto [d, p, c] = chos[index];
      if (d >= x) {
        pq.emplace(p, c);
        index--;
      } else {
        break;
      }
    }
    if (pq.empty()) break;
    auto [p, c] = pq.top();
    pq.pop();
    ans += p;
    if (c > 1) pq.emplace(p, c - 1);
  }
  cout << (x == 0 ? ans : -1) << endl;
}