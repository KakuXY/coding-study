/**
 * 判断 arr 是否有子序列等于 target
 */
template <typename T>
bool sub_match(const T &arr, const T &target) {
  size_t idx = 0;
  for (auto &elem : arr) {
    if (elem == target[idx]) {
      if (++idx == target.size()) return true;
    }
  }
  return false;
}

