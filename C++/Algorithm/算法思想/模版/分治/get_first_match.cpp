/**
 * 在 [lo, hi] 闭区间内，找到第一个满足 match 条件的值
 * 其中 match 必须符合 FF...FT...TT 的单调性
 * 如：
 * 有序数组中第一个大于等于 x 的元素下标
 * int index = get_first_match(0, n - 1, [&](int index) { return a[index] >= x; });
 * 
 * 注：如果 match 符合的是 TT...TF...F 的单调性，要求找最后一个符合条件的值
 * 依然可以使用这个模版，只需要将 match 取反，然后结果 -1 就是答案
 * 如：
 * 有序数组中最后一个小于 x 的元素下标
 * int index = get_first_match(0, n - 1, [&](int index) { return !(a[index] < x); }) - 1;
 */
template <typename T, typename M>
T get_first_match(T lo, T hi, M match) {
  while (lo <= hi) {
    T mid = lo + (hi - lo) / 2;
    if (match(mid)) hi = mid - 1;
    else lo = mid + 1;
  }
  return lo;
}