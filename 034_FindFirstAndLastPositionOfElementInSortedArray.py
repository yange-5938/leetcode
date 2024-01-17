# Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

# If target is not found in the array, return [-1, -1].

# You must write an algorithm with O(log n) runtime complexity.

 

# Example 1:

# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
# Example 2:

# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def find_start(nums, target):
            start, end = 0, len(nums) - 1
            result = -1

            while start <= end:
                mid = start + (end - start) // 2

                if nums[mid] >= target:
                    end = mid - 1
                    result = mid

                else:
                    start = mid+1

            return result

        def find_end(nums, target):
            start, end = 0, len(nums) -1
            result = -1

            while start <= end:
                mid = start + (end - start) // 2

                if nums[mid] <= target:
                    start = mid + 1
                    result = mid
                else:
                    end = mid-1
            return result

        
        start_pos = find_start(nums,target)
        end_pos = find_end(nums, target)

        if start_pos <= end_pos and start_pos != -1 and end_pos != -1:
            return [start_pos, end_pos]
        else:
            return [-1,-1]
