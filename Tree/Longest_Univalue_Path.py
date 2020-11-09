#Problem Link:- https://leetcode.com/problems/longest-univalue-path/

"""Given the root of a binary tree, return the length of the longest path, where each 
node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between 
them."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        self.ans = 0
        def helper(root):
            if not root:
                return 0
            left_length = helper(root.left)
            right_length = helper(root.right)
            final_left = 0
            final_right = 0
            if root.left and root.left.val == root.val:
                final_left = left_length + 1
            if root.right and root.right.val == root.val:
                final_right = right_length + 1
            self.ans = max(self.ans,final_left + final_right)
            return (max(final_left,final_right))
        helper(root)
        return self.ans