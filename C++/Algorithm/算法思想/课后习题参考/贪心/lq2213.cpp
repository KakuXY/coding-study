/**
 * 22 国赛 C++、Java C组 I
 *        Python B组 H
 * 打折
 * https://www.lanqiao.cn/problems/2213/learning/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int, int>> actions;
  vector<multiset<int>> prices(n + 1);
  for (int i = 0; i < m; i++) {
    int start, end, discount, cnt;
    cin >> start >> end >> discount >> cnt;
    while (cnt --) {
      int type, basePrice;
      cin >> type >> basePrice;
      prices[type].insert(basePrice);
      actions.emplace_back(start, discount, type, basePrice);
      actions.emplace_back(end + 1, -discount, type, basePrice);
    }
  }
  sort(actions.begin(), actions.end());
  long long total = 0;
  for (int i = 1; i <= n; i ++) {
    total += *prices[i].begin();
  }
  long long ans = total;
  for (auto [time, discount, type, basePrice]: actions) {
    int currentPrice = *prices[type].begin();
    if (discount > 0) {
      prices[type].insert( 1ll * basePrice * discount / 100 );
    } else {
      prices[type].erase(prices[type].find( 1ll * basePrice * (-discount) / 100 ));
    }
    int price = *prices[type].begin();
    int delta = price - currentPrice;
    total += delta;
    ans = min(ans, total);
  }
  cout << ans << endl;
}