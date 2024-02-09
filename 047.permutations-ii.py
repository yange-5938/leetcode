#
# @lc app=leetcode id=47 lang=python3
#
# [47] Permutations II
#

# @lc code=start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def backtrack(path,nums):
            if not nums:
                result.add(tuple(path))
                return
            for i in range(len(nums)):
                backtrack(path + [nums[i]], nums[:i] + nums[i+1:])
        
        
        result = set()
        backtrack([],nums)
        return [list(perm) for perm in result]
        
# @lc code=end

