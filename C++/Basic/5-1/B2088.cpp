#include<iostream>
using namespace std;
int main(){
  double prices[] = {28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
  double sum_price=0.0;
  for(auto& price : prices) {
    int cnt;
    cin >> cnt;
    sum_price += price * cnt;
  }
  cout.precision(1);
  cout << fixed;
  cout << sum_price << endl;
}