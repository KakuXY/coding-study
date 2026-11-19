#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n;
  cin >> n;
  double time = 0;
  for (int i = 0; i < n; i++)
  {
    double x, y;
    int people;
    cin >> x >> y >> people;
    double road_time = hypot(x, y) / 50 * 2;
    double go_ship = 1.0 * people;
    double down_ship = 0.5 * people;
    time += road_time + go_ship + down_ship;
  }
  cout << (int)ceil(time) << endl;
}