# Problem Link:- https://leetcode.com/problems/binary-tree-pruning/

"""We are given the head node root of a binary tree, where additionally every node's 
value is either a 0 or a 1.Return the same tree where every subtree (of the given tree) 
not containing a 1 has been removed."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return 
        root.left = self.pruneTree(root.left)
        root.right = self.pruneTree(root.right)
        if (root.val == 0) and (not root.left) and (not root.right):
            root = None
        return root