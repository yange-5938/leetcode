// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [3,2,1]

// Example 2:
// Input: root = []
// Output: []


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> list;
        appendNode(root, list);
        return list;
    }

    void appendNode(TreeNode* node, vector<int> &vec){
        // quickly check if node is null
        if (!node) return;
        
        // recursively call to its children
        appendNode(node->left, vec);
        appendNode(node->right, vec);

        vec.push_back(node->val);

    }
};
