#include <iostream>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
//  if (a < 60 && b >= 60 && c >= 60)
//  {
//    cout << 1 << endl;
//  }
//  else if(a >= 60 && b < 60 && c >= 60)
//  {
//    cout << 1 << endl;
//  }
//  else if(a >= 60 && b >= 60 && c < 60)
//  {
//    cout << 1 << endl;
//  }
//  else
//  {
//    cout << 0 << endl;
//  }

int cnt=0;
if (a < 60) cnt++;
if (b < 60) cnt++;
if (c < 60) cnt++;
cout << (cnt == 1) << endl;
}