# Given the root of a binary tree, return the postorder traversal of its nodes' values.

# Example 1:


# Input: root = [1,null,2,3]
# Output: [3,2,1]
# Example 2:

# Input: root = []
# Output: []


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        lis = []
        self.appendNode(root,lis)
        return lis


    def appendNode(self, node: Optional[TreeNode],lis: List[int]) -> None:
        if node is None:
            return
        self.appendNode(node.left,lis)
        self.appendNode(node.right,lis)
        
        lis.append(node.val)
