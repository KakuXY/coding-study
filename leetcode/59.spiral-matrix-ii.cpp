/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> nums(n, vector<int>(n));
        int cnt = 1;

        for (int startX = 0, startY = 0, offset = nums.size() - 1; startX < n / 2; startX++, startY++, offset--)
        {
            int x = startX, y = startY;

            while (y < offset)
            {
                nums[x][y++] = cnt++;
            }
            while (x < offset)
            {
                nums[x++][y] = cnt++;
            }
            while (y > startY)
            {
                nums[x][y--] = cnt++;
            }

            while (x > startX)
            {
                nums[x--][y] = cnt++;
            }
        }
        if(n % 2 == 1) nums[n / 2][n / 2] = cnt;
        return nums;
    }
};
// @lc code=end
