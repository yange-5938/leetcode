#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] Maximum Subarray
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = float('-inf')
        current_sum = 0

        for num in nums:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)
        return max_sum
    
# @lc code=end

