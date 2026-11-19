#include <iostream>
using namespace std;
int main()
{
  int dis;
  cin >> dis;
  if (dis / 1.2 > 50 + dis / 3.0)
  {
    cout << "Bike" << endl;
  }
  else if (dis / 1.2 < 50 + dis / 3.0)
  {
    cout << "Walk" << endl;
  }
  else
  {
    cout << "All" << endl;
  }
}