#include <iostream>
using namespace std;
//  方法1
// int main() {
//  int n;
//  cin >> n;
//  int cnt = 0;
//  for (int i = 1; i <= n; i++) {
//  bool flag = true;
//  int tmd = i;
//  while (tmd) {
//  if (tmd % 2 == 0) {
//  flag = false;
//  break;
// } else {
//  tmd /= 10;
//  if (tmd % 2 != 0) {
//  flag = false;
//  break;
// }
// }
//  tmd /= 10;
// }
//  if (flag) cnt++;
// }
//
//  cout << cnt << endl;
// return 0;
//}

// 方法2
// bool isGood(int x) {
// for (int index = 1; x; index ^= 1, x /= 10) {
// if (index % 2 != x % 2) return false;
//}
// return true;
//}
// int main() {
// int n;
// cin >> n;
// int cnt = 0;
// for (int i = 1; i <= n; i++) {
// if (isGood(i)) cnt++;
//}
// cout << cnt << endl;
//}

//方法3
int main(){
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 1; i <= n; i ++){
    if([](int x){
      for(int index = 1; x; index ^= 1, x /= 10){
        if(index != x % 2) return false;
      }
      return true;
    }(i)) cnt ++;
  }
  cout << cnt << endl;
}