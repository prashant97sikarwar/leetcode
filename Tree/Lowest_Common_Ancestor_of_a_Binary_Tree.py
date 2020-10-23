# Problem Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
"""Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if root is None:
            return None
        left_res = self.lowestCommonAncestor(root.left,p,q)
        right_res = self.lowestCommonAncestor(root.right,p,q)
        
        if (left_res and right_res) or (root in [p,q]):
            return root
        else:
            return left_res or right_res