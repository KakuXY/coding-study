#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int h, r;
  double pi = 3.14;
  cin >> h >> r;
  cout << ceil(20 / ((pi * pow(r, 2) * h) / 1000)) << endl;
}