#Problem Link:- https://leetcode.com/problems/find-bottom-left-tree-value/

"""Given a binary tree, find the leftmost value in the last row of the tree. """

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        d = {}
        def helper(root,depth):
            if root is None:
                return 
            d[depth] = root.val
            if root.right:
                helper(root.right,depth+1)
            if root.left:
                helper(root.left,depth+1)
        helper(root,0)
        return d[max(d.keys())]
        