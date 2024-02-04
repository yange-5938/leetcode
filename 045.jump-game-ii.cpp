/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n<= 1) return 0;

        int jumps = 0;
        int current_pos = 0;
        int max_reach = 0;

        for (int i =0;i<n-1;++i){
            max_reach = std::max(max_reach,i+nums[i]);
            if (i == current_pos){
                jumps++;
                current_pos = max_reach;
            }
        }

        return jumps;
    }
};
// @lc code=end

