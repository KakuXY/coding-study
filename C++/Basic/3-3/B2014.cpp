#include<iostream>
#include<format>
using namespace std;
int main(){
  double r;
  cin >> r;
 // cout << format("{:.4f} {:.4f} {:.4f}\n",2*r,2*3.14159*r,3.14159*r*r);
  cout.precision(4);
  cout << fixed;
  cout << 2*r << ' ' << 2*3.14159*r << ' ' << 3.14159*r*r << endl;
}