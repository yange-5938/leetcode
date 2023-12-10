// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> numMap;
        int n  = nums.size();

        // put each element into a hashmap, count it up
        for(int i =0; i<n ; ++i){
            numMap[nums[i]]++;
        }

        // return if there's one element occur more than n/2 times
        n = n/2;
        for (auto it = numMap.cbegin(); it != numMap.cend(); ++it) {
            if (it->second > n) return it->first;
        }
        return 0;
    }
};
