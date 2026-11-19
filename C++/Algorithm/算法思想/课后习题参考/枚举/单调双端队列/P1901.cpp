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
  vector<pair<int, int>> a(n);
  for (auto &[h, v]: a) cin >> h >> v;
  auto next_g = get_next_prev(a);
  auto prev_g = get_next_prev(a, true);
  vector<int> sum(n);
  for (int i = 0; i < n; i ++) {
    if (next_g[i] < n) sum[ next_g[i] ] += a[i].second;
    if (prev_g[i] >= 0) sum[ prev_g[i] ] += a[i].second;
  }
  cout << *max_element(sum.begin(), sum.end()) << endl;
}