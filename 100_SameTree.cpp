// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

// Example 1:


// Input: p = [1,2,3], q = [1,2,3]
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        iterateTree(p,q,same);
        return same;
    }

    void iterateTree(TreeNode* p, TreeNode* q, bool& same){
        if (same){
            if(!q&&!p) return;
            else if(q&&p) {
                same = q->val == p->val;
                iterateTree(p->left, q->left, same);
                iterateTree(p->right, q->right, same);
            }
            else {
                same = false;
                return;
            }
            
        }

    }

    bool checkNode(TreeNode* p, TreeNode* q){
        if (!q && !p) return true;
        else if (q && p) return (p->val)==(q->val);
        else return false;
    }
};
