// x * a = base + z * a
// y * b = base + z * b
// by - ax = (b - a) * z
// z = (by - ax) / (b - a)
#include <iostream>
using namespace std;
int main()
{
  double x, a, y, b;
  cin >> x >> a >> y >> b;
  cout.precision(2);
  cout << fixed;
  cout << (b*y-a*x)/(b-a) << endl;
}