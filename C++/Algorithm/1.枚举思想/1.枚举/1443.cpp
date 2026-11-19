#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> cards(10, 2021);

  for (int i = 1;; i++) {
    if ([&](int x) {
          for (; x; x /= 10) {
            int digit = x % 10;
            if (cards[digit] == 0) return true;
            cards[digit]--;
          }
          return false;
        }(i)) {
      cout << i - 1 << endl;
      break;
    }
  }
}