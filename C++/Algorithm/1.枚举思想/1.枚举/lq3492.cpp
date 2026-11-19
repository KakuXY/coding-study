#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> nums;
  for(auto& num : nums) cin >> num;
  int cnt = 0;
  for(int i = 0; i + 7 < 100; i ++){
    if(nums[i] == 2 && nums[i + 1] == 0 && nums[i + 2] == 2 && nums[i + 3] == 3){
      if(nums[i + 4] <= 1 && nums [i + 5] <= 2){
        if((nums[i + 6] < 3 && nums[i + 7] <= 9) || (nums[i + 6] == 3 && nums[i + 7] == (0 || 1))){
          cnt ++;
        }        
      }
    }
  }
  cout << cnt << endl;
}