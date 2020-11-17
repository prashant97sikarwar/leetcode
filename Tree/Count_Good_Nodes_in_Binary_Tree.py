#Problem Link:- https://leetcode.com/problems/count-good-nodes-in-binary-tree/
"""Given a binary tree root, a node X in the tree is named good if in the path from root to 
X there are no nodes with a value greater than X.Return the number of good nodes in the 
binary tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.ans = 0
        def helper(root,mx):
            if root is None:
                return 0
            if root.val >= mx:
                self.ans += 1
                mx = root.val
            helper(root.left,mx)
            helper(root.right,mx)
        helper(root,float("-inf"))
        return self.ans