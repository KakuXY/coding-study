#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> nums(N);
  int max = INT_MIN; 
  int sum = 0;
  for(auto& num: nums){
    cin >> num;
    if(num > max) max = num;
    sum += num;
  }
  cout << sum << ' ' << max << endl;
}


