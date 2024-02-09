#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(path, col):
            if not col:
                result.append(path[:])
                return
            for i in range(len(col)):
                backtrack(path + [col[i]],col[:i]+ col[i+1:])
        result = []
        backtrack([], nums)
        return result
    
# @lc code=end

