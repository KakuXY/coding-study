#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;


// #define NEG
constexpr int BUFFER_SIZE = 1 << 24;
class FastIO {
  char getchar() {
    static char input[BUFFER_SIZE], *start = input, *end = input;
    if (start == end) {
      start = input;
      end = start + fread(input, 1, BUFFER_SIZE, stdin);
    }
    return start == end ? 0 : *start ++;
  }
  char buffer[BUFFER_SIZE];
  int len = 0;
  void putchar(char x) {
    if (len == BUFFER_SIZE) flush();
    buffer[len ++] = x;
  }
 public:
  ~FastIO() { flush(); }
  void flush() {
    fwrite(buffer, 1, len, stdout);
    len = 0;
  }
  FastIO& operator>>(string& s) {
    char ch = getchar();
    while (!isgraph(ch)) ch = getchar();
    while (isgraph(ch)) s += ch, ch = getchar();
    return *this;
  }
  FastIO& operator>>(char *p) {
    char ch = getchar();
    while (!isgraph(ch)) ch = getchar();
    while (isgraph(ch)) *p ++ = ch, ch = getchar();
    *p = '\0';
    return *this;
  }
  FastIO& operator>>(char &c) {
    c = getchar();
    while (!isgraph(c)) c = getchar();
    return *this;
  }
  FastIO& operator>>(auto& x) {
    char c = getchar();
#ifdef NEG
    bool neg = false;
    for (; !isdigit(c); c = getchar())
      if (c == '-') neg = true;
    for (x = 0; isdigit(c); x = x * 10 + c - '0', c = getchar());
    if (neg) x = -x;
#else
    for (; !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); x = x * 10 + c - '0', c = getchar());
#endif
    return *this;
  }
  FastIO& operator<<(auto x) {
#ifdef NEG
    if (x < 0) x = -x, putchar('-');
#endif
    int sta[20], top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + '0');
    return *this;
  }
  FastIO& operator<<(char c) { return putchar(c), *this; }
  FastIO& operator<<(const char *p) {
    while (*p) putchar(*p++);
    return *this;
  }
  FastIO& operator<<(const string& s) {
    for (char c : s) putchar(c);
    return *this;
  }
} fio;
int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int c, n, m, q;
  fio >> c >> n >> m >> q;
  vector<int> X(n + 1), Y(m + 1);
  for (int i = 1; i <= n; i ++) fio >> X[i];
  for (int i = 1; i <= m; i ++) fio >> Y[i];
  debug(X);
  debug(Y);

  auto x = X, y = Y;

  auto solve = [&]() {
    if (x[1] == y[1] || x[n] == y[m]) return '0';
    if ((x[1] < y[1]) != (x[n] < y[m])) return '0';
    if (x[1] > y[1]) x.swap(y);
    // debug(x);
    // debug(y);
    int n = x.size() - 1, m = y.size() - 1;
    
    auto check = [&]() {
      vector<int> pi(n + 1), pj(m + 1), pmax(n + 1), pmin(m + 1);
      pi[1] = 1, pmax[1] = x[1];
      for (int i = 2; i <= n; i ++) {
        pi[i] = x[i] < x[ pi[i - 1] ] ? i : pi[i - 1];
        pmax[i] = max(pmax[i - 1], x[i]);
      }
      pj[1] = 1, pmin[1] = y[1];
      for (int j = 2; j <= m; j ++) {
        pj[j] = y[j] > y[ pj[j - 1] ] ? j : pj[j - 1];
        pmin[j] = min(pmin[j - 1], y[j]);
      }
      int i = pi[n], j = pj[m];
      if (pmax[n] >= y[j] || pmin[m] <= x[i]) return false;
      while (i != 1 && j != 1) {
        if (pmax[i - 1] < y[ pj[j - 1] ]) {
          j = pj[j - 1];
          continue;
        }
        if (pmin[j - 1] > x[ pi[i - 1] ]) {
          i = pi[i - 1];
          continue;
        }
        return false;
      }
      return true;
    };

    if (!check()) return '0';
    reverse(x.begin() + 1, x.end());
    reverse(y.begin() + 1, y.end());
    return check() ? '1' : '0';
  };

  fio << solve();
  while (q --) {
    int k1, k2, id, v;
    fio >> k1 >> k2;
    x = X, y = Y;
    while (k1 --) fio >> id >> v, x[id] = v;
    while (k2 --) fio >> id >> v, y[id] = v;
    fio << solve();
  }
  // cout << end
}