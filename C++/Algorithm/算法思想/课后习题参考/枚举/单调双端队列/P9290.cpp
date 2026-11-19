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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  auto next_l = get_next_prev<less>(a);
  auto next_ge = get_next_prev<greater_equal>(a);
  int ans = 0;
  for (int l = 0, r = 0; l < n;) {
    for (; next_ge[r] < next_l[l]; r = next_ge[r]);
    l = r = r + 1;
    ans ++;
  }
  cout << ans << endl;
}