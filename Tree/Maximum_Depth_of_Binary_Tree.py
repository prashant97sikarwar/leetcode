# Problem Link :- https://leetcode.com/problems/maximum-depth-of-binary-tree/

"""Given a binary tree, find its maximum depth.The maximum depth is the number of nodes 
along the longest path from the root node down to the farthest leaf node."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root):
        if root is None:
            return 0
        else:
            left = self.maxDepth(root.left)
            right =self.maxDepth(root.right)
        return 1 + max(left,right)
        