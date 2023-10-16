// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        } 
        // root node counts as depth of 1
        return search(root,1);
    }

    int search(TreeNode* node, int count){
        int leftSum = 0;
        int rightSum = 0;
        if (node->left != nullptr){
        leftSum = search(node->left, count+1);
        }
        if (node->right!= nullptr){
        rightSum = search(node->right, count+1);
        }
        return max(max(leftSum, rightSum), count);
    }
    

};
