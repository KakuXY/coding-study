#include <iostream>
#include <vector>
using namespace std;
int main() {

  int cnt = 0;
  for(int i = 1; i <= 100000000; i ++){
    int digitCnt = [](int x){
      int cnt = 0;
      for(; x; x /=10, cnt ++);
      return cnt;
    }(i);

    if(digitCnt & 1) continue;
    if([](int x, int digitCnt){
      int half = digitCnt >> 1;
      int sumLeft = 0, sumRight = 0;
      for(int index = 0; x; x /= 10, index ++){
        if(index < half) sumLeft += x % 10;
        else sumRight += x % 10;
      }
      return sumLeft == sumRight;
    }(i, digitCnt)) cnt ++;
  }
   cout << cnt << endl;
  return 0;
}