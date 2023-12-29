// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < n-3; ++i){
            // check duplicate for i
            if (i>0 && nums[i] == nums[i-1]) continue;

            for (size_t j = i+1; j<n-2;++j){
                // check duplicate for j
                if (j>i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = n-1;

                while (left < right){
                    auto current_sum  = static_cast<long>(nums[i]) + nums[j]+ nums[left]+ nums[right];

                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        //  check duplicate
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } 
                    else if (current_sum < target) ++left;
                    else --right;

                }
            }
        }

        return result;
    }
};
