# Problem Link:- https://leetcode.com/problems/binary-tree-maximum-path-sum/

"""Given a non-empty binary tree, find the maximum path sum.For this problem, a path 
is defined as any node sequence from some starting node to any node in the tree along 
the parent-child connections. The path must contain at least one node and does not need 
to go through the root."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root):
        self.ans = float("-inf")
        self.helper(root)
        return self.ans
    
    def helper(self,root):
        if not root.left and not root.right:
            self.ans = max(root.val,self.ans)
            return root.val
        left,right = 0,0
        if root.left:
            left = max(self.helper(root.left),left)
        if root.right:
            right = max(self.helper(root.right),right)
        self.ans = max(self.ans,left+right+root.val)
        return max(left,right) + root.val