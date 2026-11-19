#include <iostream>
#include<cmath>
using namespace std;
int main()
{
  int a, b, n;
  cin >> a >> b >> n;
  
  // a %= b;
  // int x;
  // while(n--){
  // a*=10;
  // x=a/b;
  // a-=b*x;
  //}
  // cout << x <<endl;

  int digit=0;
   a  %= b;
  while (n--)
  {
    a *= 10;
    digit=a/b;
    a %=b;
  }
  cout << digit << endl;
}
