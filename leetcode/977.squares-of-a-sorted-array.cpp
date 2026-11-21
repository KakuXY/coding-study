/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
#include <iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int k = nums.size() - 1;
        for(int i = 0, j = nums.size() - 1; i <= j;){
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                result[k--] = nums[i] * nums[i];
                i++;
            }else{
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};
// @lc code=end

