#Problem Link:- https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

"""Given a binary tree, return the sum of values of nodes with even-valued grandparent. 
If there are no nodes with an even-valued grandparent, return 0."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if root is None:
            return 0
        self.sm = 0
        self.helper(root,None,None)
        return self.sm
    
    def helper(self,child,parent,grandParent):
        if child is None:
            return 0
        if grandParent and grandParent.val % 2 == 0:
            self.sm += child.val
        self.helper(child.left,child,parent)
        self.helper(child.right,child,parent)
        
        