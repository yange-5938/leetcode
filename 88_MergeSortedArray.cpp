// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i = nums1.begin();
        auto j = nums2.begin();
        auto temp1 = m;
        auto temp2 = n;

        while(temp2>0){
            if(*j <= *i){
                i = nums1.insert(i, *j);
                nums1.pop_back();
                ++temp1;
                --temp2;
                ++j;

            } else {
                if(temp1 < 1) break;
                --temp1;
                ++i;
            }
        }


        while(temp2!=0){
            i = nums1.insert(i, *j);
            nums1.pop_back();
            ++i;
            --temp2;
            ++j;
        }
    }
};
