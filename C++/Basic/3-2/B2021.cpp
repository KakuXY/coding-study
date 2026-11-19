#include<iostream>
#include<format>
using namespace std;
int main(){
  float a;
  cin >> a;
  cout << format("{:.3f}",a) << endl;
}