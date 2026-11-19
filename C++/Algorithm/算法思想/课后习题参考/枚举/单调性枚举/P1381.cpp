#include <bits/stdc++.h>
using namespace std;

/**
 * 单调性枚举（区间）模版
 * [s, e] 闭区间
 * match 判断是否满足条件
 * insert 插入右端点
 * remove 删除左端点
 * update 更新答案
 *    [l, r] 是不满足条件的最大区间
 *           如果在 update 时需要使用维护的关键值，因为维护的关键值包含了 r+1，所以需要删除 r+1 进行更新后再加回去
 *    [l, r+1] 是满足条件的最小区间
 *             使用时需要判断 r+1 是否越界
 */
template<typename M, typename I, typename R, typename U>
void increaseEnumerate(int s, int e,
                       const M& match,
                       const I& insert,
                       const R& remove,
                       const U& update) {
  for (int l = s, r = s; l <= e; ) {
    while (l == r || (r <= e && !match(l, r - 1))) insert(l, r++);
    if (match(l, r - 1)) update(l, r - 2);
    else update(l, r - 1);
    remove(l++, r);
  }
}

int main() {
  int n;
  cin >> n;
  unordered_map<string, int> dict;
  for (int i = 0; i < n; i ++) {
    string s;
    cin >> s;
    dict[s] = 0;
  }
  int m;
  cin >> m;
  vector<string> words(m);
  unordered_set<string> uniqueWords;
  for (auto &word : words) {
    cin >> word;
    if (dict.find(word) != dict.end()) {
      uniqueWords.insert(word);
    }
  }
  int total = uniqueWords.size();
  cout << total << endl;
  if (total == 0) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 0;
  int ans = words.size();
  increaseEnumerate(0, m - 1,
    [&](int l, int r) {
      return cnt == total;
    },
    [&](int l, int r) {
      if (dict.find(words[r]) != dict.end()) {
        if (dict[words[r]] == 0) cnt ++;
        dict[words[r]] ++;
      }
    },
    [&](int l, int r) {
      if (dict.find(words[l]) != dict.end()) {
        dict[words[l]] --;
        if (dict[words[l]] == 0) cnt --;
      }
    },
    [&](int l, int r) {
      if (r + 1 == words.size()) return;
      ans = min(ans, r - l + 2);
    });
  cout << ans << endl;
}
