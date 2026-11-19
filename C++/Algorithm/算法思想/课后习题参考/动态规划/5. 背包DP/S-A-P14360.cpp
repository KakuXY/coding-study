#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

template<int mod>
struct modint {
  int _v;
  // 初始化
  modint() : _v(0) {}
  template<typename T>
  modint(T v) : _v((v % mod + mod) % mod) {}

  // 一元操作符
  modint& operator++() {
    if (++_v == mod) _v = 0;
    return *this;
  }
  modint& operator--() {
    if (_v == -1) _v = mod - 1;
    return *this;
  }
  modint operator++(int) {
    modint temp = *this;
    if (++_v == mod) _v = 0;
    return temp;
  }
  modint operator--(int) {
    modint temp = *this;
    if (_v == -1) _v = mod - 1;
    return temp;
  }
  modint operator+() const { return *this; }
  modint operator-() const { return modint(0) - *this; }

  // 自运算
  modint& operator+= (const modint& rhs) {
    _v += rhs._v;
    if (_v >= mod) _v -= mod;
    return *this;
  }
  modint& operator-= (const modint& rhs) {
    _v -= rhs._v;
    if (_v < 0) _v += mod;
    return *this;
  }
  modint& operator*= (const modint& rhs) {
    _v = (unsigned long long)_v * rhs._v % mod;
    return *this;
  }
  modint& operator/= (const modint& rhs) { return *this *= rhs.inv(); }

  // 二元运算
  friend modint operator+ (const modint& lhs, const modint& rhs) { return modint(lhs._v) += rhs; }
  friend modint operator- (const modint& lhs, const modint& rhs) { return modint(lhs._v) -= rhs; }
  friend modint operator* (const modint& lhs, const modint& rhs) { return modint(lhs._v) *= rhs; }
  friend modint operator/ (const modint& lhs, const modint& rhs) { return modint(lhs._v) /= rhs; }
  friend bool operator== (const modint& lhs, const modint& rhs) { return lhs._v == rhs._v; }
  friend bool operator!= (const modint& lhs, const modint& rhs) { return lhs._v != rhs._v; }

  // 逆元，默认 mod 是质数
  modint inv() const {
    modint res = 1, x = _v;
    for (int n = mod - 2; n; n /= 2, x *= x) {
      if (n & 1) res *= x;
    }
    return res;
  }

  // 输入输出
  friend ostream& operator<< (ostream& os, const modint& rhs) {
    return os << rhs._v;
  }
  friend istream& operator>> (istream& is, modint& rhs) {
    return is >> rhs._v;
  }
};
using mint = modint<998244353>;
// using mint = modint<1000000007>;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i ++) cin >> a[i];
  sort(a.begin(), a.end());
  int m = a[n];
  vector<array<mint, 3>> dp(m + 2, {0, 0, 0});
  dp[0][0] = 1;
  mint ans = 0;
  for (int i = 1; i <= n; i ++) {
    for (int j = a[i] + 1; j <= m + 1; j ++) {
      ans += dp[j][2];
    }
    for (int j = m + 1; j >= 0; j --) {
      for (int k = 0; k <= 2; k ++) {
        dp[min(m + 1, a[i] + j)][min(2, k + 1)] += dp[j][k];
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  for (int cas = 1; cas <= T; cas ++) {
    solve();
  }
}