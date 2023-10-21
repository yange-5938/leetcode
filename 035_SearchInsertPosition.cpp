// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();

        if (size==0) return 0;

        for(int i =0; i<size; i++){
            if (nums[i] >= target){
                return i;
            }
        }

        return size;
    }
};
