#include <iostream>
#include <format>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b;
  int res = 1;
  while (b--)
  {
    res *= a;
    res %= 1000;
  }

 // cout << format("{:03d}", res) << endl;
 
 cout.width(3);
 cout.fill('0');
 cout<<res<<endl;
}
