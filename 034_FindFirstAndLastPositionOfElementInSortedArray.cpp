// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findStart(nums, target), end = findEnd(nums, target);

        if (start <= end && start != -1 && end != -1) return {start, end};
        else return {-1,-1};
        
    }
private:
    int findStart(const std::vector<int>& nums,const int& target){
        int start = 0, end = nums.size() - 1, result = -1 ;

        while(start <= end){
            int mid = start + (end-start) /2;

            if (nums[mid] >= target){
                end = mid - 1;
                result = mid;
            } else start = mid + 1;
        }
        return result;
    }


    int findEnd(const std::vector<int>& nums,const int& target){
        int start = 0, end = nums.size() - 1, result = -1 ;

        while(start <= end){
            int mid = start + (end-start) /2;

            if (nums[mid] <= target){
                start = mid + 1;
                result = mid;
            } else end = mid - 1;
        }
        return result;
    }  
};
