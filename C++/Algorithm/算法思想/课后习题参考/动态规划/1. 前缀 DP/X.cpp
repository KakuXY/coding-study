#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  while (T --) {
    int n;
    string str;
    cin >> n >> str;
    // [0000][11111][00000]
    // f(i, one): 前 i 个字符，当前处于第一段（都是0），最小改变量
    // f(i, two): 前 i 个字符，当前处于第二段（都是1），最小改变量
    // f(i, three): 前 i 个字符，当前处于第三段（都是0），最小改变量
    int one = 0, two = 0, three = 0;
    for (char c : str) {
      three = min(three, two) + (c != '0');
      two = min(two, one) + (c != '1');
      one = one + (c != '0');
    }
    cout << min({one, two, three}) << endl;
  }
}