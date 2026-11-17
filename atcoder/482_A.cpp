#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int cnt = 0;
    for (auto &s : S)
    {
        if (s == 'o')
            cnt++;
    }
    if (cnt % 2 == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
}
