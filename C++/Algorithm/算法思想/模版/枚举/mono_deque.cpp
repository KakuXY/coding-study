#include <deque>
using namespace std;

/**
 * 单调双端队列
 * 默认：单调递减，可获取最大值
 * usage:
 * mono_deque<int> dec_q; // 默认单调递减，greater 代表大于，即: a[0] > a[1] > ...
 * mono_deque<int, less> inc_q; // 单调递增，less 代表小于，即: a[0] < a[1] < ...
 * inc_q.push(i, a[i]); 将坐标和元素 push 进队列
 * inc_q.shrink_to(i); 将坐标小于等于 i 的元素删除
 * inc_q.get_extremum(); 获取队列中极值
 * 
 * 可以链式调用
 * inc_q.push(i, a[i]).shrink_to(i - k).get_extremum();
 */
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