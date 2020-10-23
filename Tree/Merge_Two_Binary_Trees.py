#Problem Link :- https://leetcode.com/problems/merge-two-binary-trees/

"""Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.You need to merge them 
into a new binary tree. The merge rule is that if two nodes overlap, then sum node values 
up as the new value of the merged node. Otherwise, the NOT null node will be used as the node 
of new tree."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def mergeTrees(self, t1, t2):
        if t1 is None:
            return t2
        if t2 is None:
            return t1
        if t1 and t2:
            root = TreeNode(t1.val + t2.val)
        root.left = self.mergeTrees(t1.left,t2.left)
        root.right = self.mergeTrees(t1.right,t2.right)
        return root
            