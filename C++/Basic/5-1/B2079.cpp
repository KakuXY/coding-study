#include<iostream>
using namespace std;
int main(){
  int n;
  cin >>n;
  double a[16];
  fill(a+1 , a + 16, 1.0);

  for(int i = 1; i <= n ; i++){
    int cnt;
    cnt = i;
    do{
      if (cnt <= 0) break;
      a[i] *= cnt;
    }while(cnt--);
  }

  double sum = 1.0;
  do{
    if (n <= 0) break;
    sum += 1/a[n];
  }while(n--);

  cout.precision(10);
  cout << fixed;
  cout << sum << endl;
}