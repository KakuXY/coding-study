/**
 * 23 省赛 Java、Python C 组 D
 * 平均
 * https://www.lanqiao.cn/problems/3532/learning/
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> scores[10];
  for (int i = 0; i < n; i ++) {
    int d, s;
    cin >> d >> s;
    scores[d].push_back(s);
  }
  long long ans = 0;
  for (int i = 0; i < 10; i ++) {
    sort(scores[i].begin(), scores[i].end(), greater<int>());
    for (int j = n / 10; j < scores[i].size(); j ++) {
      ans += scores[i][j];
    }
  }
  cout << ans << endl;
}