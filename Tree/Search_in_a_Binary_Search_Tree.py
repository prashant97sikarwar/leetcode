# Problem Link :- https://leetcode.com/problems/search-in-a-binary-search-tree/

"""Given the root node of a binary search tree (BST) and a value. You need to find 
the node in the BST that the node's value equals the given value. Return the subtree 
rooted with that node. If such node doesn't exist, you should return NULL."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def searchBST(self, root, val):
        if root is None:
            return 
        if root.val == val:
            return root
        if root.val > val:
            return self.searchBST(root.left,val)
        if root.val < val:
            return self.searchBST(root.right,val)