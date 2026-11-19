#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >> n;
  // cout << (n == 1 || n == 3 || n == 5 ? "NO" : "YES") << endl;
  cout << (n % 2 && n != 7 ? "NO" : "YES") << endl;
}