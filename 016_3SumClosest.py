# Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

# Return the sum of the three integers.

# You may assume that each input would have exactly one solution.

 

# Example 1:

# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
# Example 2:

# Input: nums = [0,0,0], target = 1
# Output: 0
# Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        
        # take the first 3 as initial value
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):

            left, right = i+1, len(nums) - 1

            while left < right:

                current_sum = nums[i] + nums[left] + nums[right]
                current_diff = current_sum - target

                if abs(current_diff) < abs(closest - target):
                    closest = current_sum
                    left +=1
                elif current_diff < 0:
                    left += 1
                else:
                    right -= 1
        
        return closest
