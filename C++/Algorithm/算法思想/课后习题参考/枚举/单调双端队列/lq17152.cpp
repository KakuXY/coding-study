/**
 * 最大区间
 * 23 国赛 Java 研究生 F 
 *         C++ 研究生 E
 *         C++ C H
 */
#include <bits/stdc++.h>
using namespace std;
template <template<typename> typename Cmp = greater, typename T>
vector<int> get_next_prev(vector<T> &arr, bool prev = false) {
  int n = arr.size();
  vector<int> res(n);
  stack<int> st;
  for (int i = prev ? 0 : n - 1; prev ? i < n : i >= 0; prev ? ++i : --i) {
    while (!st.empty() && !Cmp<T>()(arr[st.top()], arr[i])) st.pop();
    res[i] = st.empty() ? (prev ? -1 : n) : st.top();
    st.push(i);
  }
  return res;
}
int main() {
  // for L : [1, n]
  //    for R : [L, n]
  //       min(A[L:R]) * (R - L + 1)
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto prev_l = get_next_prev<less>(a, true);
  auto next_l = get_next_prev<less>(a);
  long long ans = 0;
  for (int i = 0; i < n; i ++) {
    ans = max(ans, (next_l[i] - prev_l[i] - 1ll) * a[i]);
  }
  cout << ans << endl;
}