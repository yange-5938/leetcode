// Given a binary tree, determine if it is 
// height-balanced
// .

 // Example 1:


// Input: root = [3,9,20,null,null,15,7]
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
    bool isBalanced(TreeNode* root) {
        return compareNodes(root);
    }

    bool compareNodes(TreeNode* node){
        if (!node)  return true;
        auto left = node->left;
        auto right = node->right;
        bool dif = false;

        if (left && right){
            dif = abs(nodeDepth(left)-nodeDepth(right)) < 2;
            if (dif){
                auto compLeft = compareNodes(left);
                auto compRight = compareNodes(right);
                dif = compLeft && compRight;
            }

        } else if (left){
            dif = nodeDepth(left) < 2;
        } else if (right){
            dif = nodeDepth(right) < 2;
        } else{
            dif = true;
        }
        return dif;

    }

    int nodeDepth(TreeNode* node){
        if (!node) return 0;
        auto left = node->left;
        auto right = node->right;

        if(left && right){
            return 1 + max(nodeDepth(left), nodeDepth(right));
        } else if(left){
            return 1 + nodeDepth(left);
        } else if (right){
            return 1 + nodeDepth(right);
        } else{
            return 1;
        }
    }
};
