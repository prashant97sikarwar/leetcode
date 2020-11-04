# Problem Link:- https://leetcode.com/problems/invert-binary-tree/

"""Invert a binary tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root):
        if root is not None:
            root.left, root.right = root.right, root.left
            if root.left:
                self.invertTree(root.left)
            if root.right:
                self.invertTree(root.right)
        return root