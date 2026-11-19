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
  // stack<int> st;
  // vector<int> next_g(n);
  // for (int i = n - 1; i >= 0; i --) {
  //   while (!st.empty() && a[ st.top() ] <= a[i]) {
  //     st.pop();
  //   }
  //   if (st.empty()) next_g[i] = -1;
  //   else next_g[i] = st.top();
  //   st.push(i);
  // }
  auto next_g = get_next_prev<greater>(a);
  for (int i = 0; i < n; i ++) {
    if (next_g[i] == n) cout << 0 << ' ';
    else cout << next_g[i] + 1 << ' ';
  }
  cout << endl;
}