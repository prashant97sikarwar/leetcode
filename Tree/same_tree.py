# Problem Link :- https://leetcode.com/problems/same-tree/

"""Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and 
the nodes have the same value."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        return p.val == q.val and self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)