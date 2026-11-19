#include <iostream>
using namespace std;
int main()
{
//  int x;
//  cin >> x;
//  if (x % 3 && x % 5 && x % 7)
//  {
//    cout << "n" << endl;
//  }
//  else if (x % 3 && x % 5)
//  {
//    cout << 7 << endl;
//  }
//  else if (x % 5 && x % 7)
//  {
//    cout << 3 << endl;
//  }
//  else if (x % 3 && x % 7)
//  {
//    cout << 5 << endl;
//  }
//  else if (x % 3)
//  {
//    cout << 5 << " " << 7 << endl;
//  }
//  else if (x % 5)
//  {
//    cout << 3 << " " << 7 << endl;
//  }
//  else if (x % 7)
//  {
//    cout << 3 << " " << 5 << endl;
//  }
//  else
//  {
//    cout << 3 << " " << 5 << " " << 7 << endl;
//  }

 int n;
  cin >> n;
  // if (n % 105 == 0) puts("3 5 7");
  // else if (n % 15 == 0) puts("3 5");
  // else if (n % 21 == 0) puts("3 7");
  // else if (n % 35 == 0) puts("5 7");
  // else if (n % 3 == 0) puts("3");
  // else if (n % 5 == 0) puts("5");
  // else if (n % 7 == 0) puts("7");
  // else puts("n");
  if (n % 3 && n % 5 && n % 7) puts("n");
  else {
    if (n % 3 == 0) cout << "3 ";
    if (n % 5 == 0) cout << "5 ";
    if (n % 7 == 0) cout << "7 ";
  }
  cout << endl;
}