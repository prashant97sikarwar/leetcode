# Problem Link :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

"""Given the root of a Binary Search Tree and a target number k, return true if there 
exist two elements in the BST such that their sum is equal to the given target."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findTarget(self, root, k):
        s = set()
        return self.helper(root,k,s)
        
    def helper(self,root,k,s):
        if root is None:
            return False
        if k-root.val in s:
            return True
        s.add(root.val)
        return self.helper(root.left,k,s) or self.helper(root.right,k,s)