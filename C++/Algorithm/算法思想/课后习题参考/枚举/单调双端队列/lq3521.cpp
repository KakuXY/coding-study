/**
 * 23 省赛 Python A组 F
 *    省赛 c++ C组 F
 *    省赛 Java C 组 G
 * 子矩阵
 * https://www.lanqiao.cn/problems/3521/learning/
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T, template<typename> typename Cmp = greater>
class mono_deque : public deque<pair<int, T>> {
 public:
  mono_deque& push(int idx, const T &x) {
    while (!this->empty() && !Cmp<T>()(this->back().second, x)) this->pop_back();
    this->push_back({idx, x});
    return *this;
  }
  mono_deque& shrink_to(int idx) {
    while (!this->empty() && this->front().first <= idx) this->pop_front();
    return *this;
  }
  T get_extremum() { return this->front().second; }
};

constexpr int mod = 998244353;
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  auto maze = vector(n, vector<int>(m));
  for (auto &row : maze) {
    for (auto &x : row)  cin >> x;
  }
  auto row_max = vector(n, vector<int>(m));
  auto row_min = vector(n, vector<int>(m));
  // [高度 a]
  for (int y = 0; y < m; y ++) {
    mono_deque<int, less> inc_q;
    mono_deque<int> dec_q;
    for (int x = 0; x < n; x ++) {
      row_min[x][y] = inc_q.push(x, maze[x][y]).shrink_to(x - a).get_extremum();
      row_max[x][y] = dec_q.push(x, maze[x][y]).shrink_to(x - a).get_extremum();
    }
  }
  int ans = 0;
  // [宽度 b]
  for (int x = a - 1; x < n; x++) {
    mono_deque<int, less> inc_q;
    mono_deque<int> dec_q;
    for (int y = 0; y < m; y++) {
      dec_q.push(y, row_max[x][y]).shrink_to(y - b);
      inc_q.push(y, row_min[x][y]).shrink_to(y - b);
      if (y >= b - 1) {
        ans = (ans + 1ll * dec_q.get_extremum() * inc_q.get_extremum()) % mod;
      }
    }
  }
  cout << ans << endl;
}