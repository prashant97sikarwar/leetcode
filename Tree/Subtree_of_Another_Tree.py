#  Problem link:- https://leetcode.com/problems/subtree-of-another-tree/

"""Given two non-empty binary trees s and t, check whether tree t has exactly the same 
structure and node values with a subtree of s. A subtree of s is a tree consists of a 
node in s and all of this node's descendants. The tree s could also be considered as a 
subtree of itself."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubtree(self, s, t):
        def is_the_same(s, t):
            if not s and not t:
                return True
            
            elif s and t:
                return s.val == t.val and is_the_same(s.left, t.left) and is_the_same(s.right, t.right)
            else:
                return False
        return bool(s and t) and (is_the_same(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t))