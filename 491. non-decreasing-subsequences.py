# Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 

# Example 1:

# Input: nums = [4,6,7,7]
# Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
# Example 2:

# Input: nums = [4,4,3,2,1]
# Output: [[4,4]]
 

# Constraints:

# 1 <= nums.length <= 15
# -100 <= nums[i] <= 100

class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        def backtrack(start, subseq):
            if len(subseq) > 1:
                result.add(tuple(subseq[:]))

            for i in range(start,len(nums)):
                if not subseq or nums[i] >= subseq[-1]:
                    backtrack(i+1,subseq+[nums[i]])

        
        result = set()
        backtrack(0,[])
        return result
