// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return compareSym(root->left, root->right);
    }

    bool compareSym(TreeNode* leftNode, TreeNode* rightNode){
        if (!leftNode && !rightNode) return true;
        else if (!leftNode) return false;
        else if (!rightNode) return false;
        
        if (leftNode->val != rightNode->val) return false;

        bool leftSum = compareSym(leftNode->left, rightNode->right);
        bool rightSum = compareSym(leftNode->right, rightNode->left);

        return (leftSum && rightSum);
    
    }
};
