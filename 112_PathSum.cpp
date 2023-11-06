// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

 

// Example 1:


// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool hasSum = false;
        if(root) searchSum(root, 0, hasSum, targetSum);
        return hasSum;
    }

    void searchSum(TreeNode* node, int beforeSum, bool& hasSum, const int& targetSum){               
        int sumNow = beforeSum + node->val;
        if (node->left){
            searchSum(node->left, sumNow, hasSum, targetSum);
        }

        if(node->right){
            searchSum(node->right, sumNow, hasSum, targetSum);
        }

        if (!node->right && !node->left){
            if(sumNow == targetSum) hasSum = true;
        }
    }
};
