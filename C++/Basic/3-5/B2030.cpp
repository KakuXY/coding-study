#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double Xa, Ya, Xb, Yb;
  cin >> Xa >> Ya;
  cin >> Xb >> Yb;
  double Xdiff = Xa - Xb;
  double Ydiff = Ya - Yb;
  cout.precision(3);
  cout << fixed;
  cout << hypot(Xdiff, Ydiff) << endl;
}