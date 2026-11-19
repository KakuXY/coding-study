#include <iostream>
using namespace std;
int main()
{
  unsigned int x;
  int y;
  cin >> x >> y;
  if (y < 0)
  {
    cout << ">" << endl;
  }
  else if (x > y)
  {
    cout << ">" << endl;
  }
  else if (x < y)
  {
    cout << "<" << endl;
  }
  else
  {
    cout << "=" << endl;
  }
}
