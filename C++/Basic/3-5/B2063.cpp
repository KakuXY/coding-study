#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int x, n;
  cin >> x >> n;
  cout.precision(4);
  cout << fixed;
  cout << x * pow((1 + 0.001), n) << endl;
}