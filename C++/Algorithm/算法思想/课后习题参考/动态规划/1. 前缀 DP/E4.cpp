#include <bits/stdc++.h>
#ifndef DEBUG
#define debug
#endif
using namespace std;
using i64 = int64_t;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string str;
  cin >> str;
  int n = str.size();
  
  int steal = 0, not_steal = 0;
  for (int i = 0; i < n; i ++) {
    int v = str[i] - 'a' + 1;
    if (i == 0) {
      steal = v;
    } else {
      int temp = max(steal, not_steal);
      steal = not_steal + v;
      not_steal = temp;
    }
  }
  cout << max(steal, not_steal) << endl;
}