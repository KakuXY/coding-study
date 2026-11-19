#include <iostream>
#include <format>
using namespace std;
int main()
{
  int n;
  double num = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    double a=1;
    for (int j = 1; j <= i; j++)
    {
      a *= j;
    }
    num += 1 / a;
  }
  cout << format("{:.10f}",  num) << endl;
}
