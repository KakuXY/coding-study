/**
 * https://acm.hdu.edu.cn/showproblem.php?pid=1789
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    int total = 0, maxD = 0;
    for (auto &[d, _] : arr) {
      cin >> d;
      maxD = max(maxD, d);
    }
    // for (int i = 0; i < n; i ++) arr[i].first;
    for (auto &[_, s] : arr) {
      cin >> s;
      total += s;
    }
    vector<vector<int>> scores(maxD + 1);
    for (auto &[d, s] : arr) scores[d].push_back(s);
    priority_queue<int> pq;
    for (int i = maxD; i >= 1; i --) {
      for (auto &s : scores[i]) pq.push(s);
      if (pq.size()) {
        total -= pq.top();
        pq.pop();
      }
    }
    cout << total << endl;
  }
}
