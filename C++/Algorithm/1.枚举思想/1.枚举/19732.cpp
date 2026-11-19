#include <math.h>
#include <iostream>
using namespace std;
int main() {
  cout.precision(2);
  cout << fixed;
  int dx = 15, dy = 17;
  int width = 343720 * 2, highth = 233333 * 2;
  for (int t = 1;; t++) {
    if (t * dx % width == 0 && t * dy % highth == 0) {
      cout << hypot(t * dx, t * dy) << endl;
      break;
    }
  }
  return 0;
}