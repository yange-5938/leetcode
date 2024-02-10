#
# @lc app=leetcode id=47 lang=python3
#
# [47] Permutations II
#

# @lc code=start
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        #########################################
        # A trivial way is to do normal permutation with backtrack
        # and put all solution into a set, so everything is unique.
        # 
        # def backtrack(path,nums):
        #     if not nums:
        #         result.add(tuple(path))
        #         return
        #     for i in range(len(nums)):
        #         backtrack(path + [nums[i]], nums[:i] + nums[i+1:])
        #
        #
        # result = set()
        # backtrack([],nums)
        # return [list(perm) for perm in result]
        #
        ######################################
    

        # A better way would be sort it first, and then check if the newer
        # one is same as the last one 
        
        def backtrack(path, nums):
            if not nums:
                result.append(path[:])
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                backtrack(path+[nums[i]], nums[:i]+nums[i+1:])

        nums.sort()
        result = []
        backtrack ([],nums)
        return result

        
# @lc code=end

