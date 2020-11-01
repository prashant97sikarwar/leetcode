#  Problem Link :- https://leetcode.com/problems/symmetric-tree/

"""Given a binary tree, check whether it is a mirror of itself 
(ie, symmetric around its center)."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root):
        def isMirror(root1,root2):
            if root1 is None and root2 is None:
                return True
            if root1 is not None and root2 is not None:
                if root1.val == root2.val:
                    return isMirror(root1.left,root2.right) and isMirror(root1.right,root2.left)
        return isMirror(root,root)