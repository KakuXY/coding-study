/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = nums.size();
        int sum = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                   int subL = j - i + 1;
                   result = min(result, subL);
                   sum -= nums[i];
                   i++;
            }
        }
        if(i == 0) return 0;
        else return result;
    }
};
// @lc code=end

