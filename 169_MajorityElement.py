# Given an array nums of size n, return the majority element.

# The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

# Example 1:

# Input: nums = [3,2,3]
# Output: 3
# Example 2:

# Input: nums = [2,2,1,1,1,2,2]
# Output: 2

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        numMap = defaultdict(int)

        for num in nums:
            numMap[num] += 1
        
        n = n // 2
        for k, v in numMap.items():
            if v > n:
                return k

        return 0
