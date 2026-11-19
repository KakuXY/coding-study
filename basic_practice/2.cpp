#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> nums(N);
  int max_cnt = 0;
  for(auto& num: nums) cin >> num;

  int max = INT_MIN;
  for(size_t i = 0; i < nums.size(); i++){
    if(i == 0 || nums[i] > max){
      max = nums[i];
      max_cnt++;
    }
  }

  cout << max_cnt << endl;

}