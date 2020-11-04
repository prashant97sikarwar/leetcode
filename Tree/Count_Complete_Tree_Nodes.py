# Problem Link :- https://leetcode.com/problems/count-complete-tree-nodes/
"""Given a complete binary tree, count the number of nodes."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root):
        if root is None:
            return 0
        else:
            return self.fun(root)
        
        
    def fun(self,node):
        if node is None:
            return 0
        left = node.left
        lh = 1
        while left is not None:
            left = left.left
            lh += 1
        right = node.right
        lr = 1
        while right is not  None:
            right = right.right
            lr += 1
        if lr == lh:
            return (2 ** lr) - 1
        else:
            self.fun(node.left)
            self.fun(node.right)