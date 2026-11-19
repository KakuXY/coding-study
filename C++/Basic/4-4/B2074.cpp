#include <iostream>
using namespace std;
int main()
{
  int a, b,weekday=1;
  cin >> a >> b;
  while(b--){
    weekday *= a;
    weekday %= 7;
  }
  switch (weekday)
  {
  case 1:
    cout << "Monday" << endl;
    break;
  case 2:
    cout << "Tuesday" << endl;
    break;
  case 3:
    cout << "Wednesday" << endl;
    break;
  case 4:
    cout << "Thursday" << endl;
    break;
  case 5:
    cout << "Friday" << endl;
    break;
  case 6:
    cout << "Saturday" << endl;
    break;
  default:
    cout << "Sunday" << endl;
    break;
  }
}