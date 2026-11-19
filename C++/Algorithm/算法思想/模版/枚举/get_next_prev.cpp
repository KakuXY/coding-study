#include <vector>
using namespace std;
/**
 * 获取【下/上】一个比当前元素【大/小/大于等于/小于等于】的元素下标
 * 默认：获取【下】一个比当前元素【大】的元素下标
 * usage:
 * auto next_g = get_next_prev<greater>(a);
 * auto prev_l = get_next_prev<less>(a, true);
 * auto next_ge = get_next_prev<greater_equal>(a);
 */
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