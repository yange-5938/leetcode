// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;
        auto begin1 = nums.begin();
        auto end1 = nums.begin()+mid;
        auto begin2 = nums.size() % 2 == 0 ? nums.end() - mid + 1 : nums.end() - mid;
        auto end2 = nums.end();
        TreeNode* root = new TreeNode(nums[mid]);
        buildTree(root, begin1, end1, begin2,end2);
        return root;
    }

    void buildTree(TreeNode* node, std::vector<int>::iterator begin1, std::vector<int>::iterator end1,std::vector<int>::iterator begin2, std::vector<int>::iterator end2  ){
        // build left subtree
        int size1 = std::distance(begin1, end1);
        if (size1 >0 ){
            int mid1 = size1 / 2;
            auto begin11 = begin1;
            auto end11 = begin1+mid1;
            auto begin12 = size1 % 2 == 0 ? end1 - mid1 + 1 : end1 - mid1;
            auto end12 = end1;
            TreeNode* leftNode = new TreeNode(*end11);
            node->left = leftNode;
            buildTree(leftNode, begin11, end11, begin12,end12);
        }

        // build right subtree
        int size2 = std::distance(begin2, end2);
        if (size2 >0 ){
            int mid2 = size2 / 2;
            auto begin21 = begin2;
            auto end21 = begin2+mid2;
            auto begin22 = size2 % 2 == 0 ? end2 - mid2 + 1 : end2 - mid2;
            auto end22 = end2;
            TreeNode* rightNode = new TreeNode(*end21);
            node->right = rightNode;
            buildTree(rightNode, begin21, end21, begin22,end22);
        }
    }

};
