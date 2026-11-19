#include <iostream>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  for (int x = 2; x < 1000000; x++)
  {
    int a1, b1, c1;
    a1 = a % x;
    b1 = b % x;
    c1 = c % x;
    if (a1 == b1 && b1 == c1)
    {
      cout << x << endl;
      break;
    }
  }
}