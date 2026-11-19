#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

  int n,r;
  cin >> n >> r;

  vector<int> v;
  while(n > 0){
    v.push_back(n % r);
    n /= r;
  }

  reverse(v.begin(), v.end());

  for(auto& d: v){
    if(d < 10) cout << d;
    else cout << char('A' + d - 10);
  }
  cout << endl;
}