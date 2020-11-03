# Problem Link :- https://leetcode.com/problems/sum-root-to-leaf-numbers/

"""Given a binary tree containing digits from 0-9 only, each root-to-leaf path could 
represent a number.An example is the root-to-leaf path 1->2->3 which represents the 
number 123.Find the total sum of all root-to-leaf numbers"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumNumbers(self, root):
        if root is None:
            return 0
        self.ans = 0
        self.helper(root,0)
        return self.ans
    
    def helper(self,root,val):
        if root is None:
            return 0
        val = 10*val + root.val
        if not root.left and not root.right:
            self.ans += val
            return 
        self.helper(root.left,val)
        self.helper(root.right,val)
        