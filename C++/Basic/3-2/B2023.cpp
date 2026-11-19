#include<iostream>
#include<format>
using namespace std;
int main(){
  char a;
  int b;
  float c;
  double d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cout << format("{:c} {} {:.6f} {:.6f}",a,b,c,d) << endl;
}