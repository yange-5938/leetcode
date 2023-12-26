// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the vector
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        // initialize the result with the first 3 elements
        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n-2; ++i){
            
            int left = i+1;
            int right = n -1;

            while (left < right){
                int currentSum = nums[i]+ nums[left]+ nums[right];
                int currentDiff = currentSum - target;

                if (std::abs(currentDiff) < std::abs(target - result)) {
                    result = currentSum;
                    left++;
                } else if (currentDiff < 0) left++;
                else right--;
            }
        }

        return result;
    }
};
