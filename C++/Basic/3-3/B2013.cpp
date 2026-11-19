#include<iostream>
using namespace std;
int main(){
  double f;
  cin >> f;
  cout.precision(5);
  cout << fixed;
  cout << 5*(f-32)/9 << endl;
}