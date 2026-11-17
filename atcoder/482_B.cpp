#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  vector<string> strings(5);

  for (auto &s : strings)
    cin >> s;

  vector<int> nums;

  for (int i = 0; i < 5; i++)
  {
    int cnt = 0;
    for (int j = 0; j < 5; j++)
    {
      if (strings[i][j] == 'o')
        cnt++;
    }
    nums.push_back(cnt);
  }

  for (int i = 0; i < 5; i++)
  {
    int cnt = 0;
    for (int j = 0; j < 5; j++)
    {
      if (strings[j][i] == 'o')
        cnt++;
    }
    nums.push_back(cnt);
  }

  int cnt = 0;
  for (int i = 0, j = 0; i < 5 && j < 5; i++, j++)
  {
    if (strings[i][j] == 'o')
      cnt++;
  }
  nums.push_back(cnt);

  cnt = 0;
  for (int i = 0, j = 4; i < 5 && j >= 0; i++, j--)
  {

    if (strings[i][j] == 'o')
      cnt++;
  }
  nums.push_back(cnt);

  sort(nums.begin(), nums.end());

  cout << 5 - nums.back() << endl;
}
