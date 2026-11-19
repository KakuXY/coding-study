#include<iostream>
using namespace std;
int main(){
  int a,b,c,d,e,sum;
  cin >> a >> b >> c >> d >> e;
  sum=a%3;
  a=a/3;
  e=e+a;
  b=b+a;
  sum=sum+b%3;
  b=b/3;
  a=a+b;
  c=c+b;
  sum=sum+c%3;
  c=c/3;
  b=b+c;
  d=d+c;
  sum=sum+d%3;
  d=d/3;
  c=c+d;
  e=e+d;
  sum=sum+e%3;
  e=e/3;
  d=d+e;
  a=a+e;
  cout << a << " " << b << " " << c << " " << d << " " << e <<endl;
  cout << sum << endl;
}