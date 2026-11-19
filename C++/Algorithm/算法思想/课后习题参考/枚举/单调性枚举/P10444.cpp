#include <bits/stdc++.h>
using namespace std;

int main() {
  // 1 1 4 5 1 4
  // 1 1 1 4 4 5
  // [1 max]  [min 5]
  // max - 1 == 5 - min
  // max + min == 5 + 1
  // a + b == target
  int T, id;
  cin >> T >> id;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int target = a[0] + a[n - 1];
    cout << [&]() {
      for (int l = 1, r = n - 2; l < r;) {
        if (a[l] + a[r] > target) {
          r--;
        } else if (a[l] + a[r] < target) {
          l++;
        } else {
          return "Yes";
        }
      }
      return "No";
    }() << endl;
  } 
}