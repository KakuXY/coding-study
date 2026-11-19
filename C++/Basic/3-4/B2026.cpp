#include <iostream>
using namespace std;
int main()
{
  double a, b;
  cin >> a >> b;
  //cout.precision(5);
  //cout << fixed;
  cout << a - int(a / b) * b << endl;
}