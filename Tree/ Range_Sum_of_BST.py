# Problem Link :- https://leetcode.com/problems/range-sum-of-bst/

"""Given the root node of a binary search tree, return the sum of values of all nodes with 
value between L and R (inclusive).The binary search tree is guaranteed to have unique values."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def rangeSumBST(self, root, L, R):
        if root is None:
            return 0
        if root.val >= L and root.val <= R:
            return root.val + self.rangeSumBST(root.left,L,R) + self.rangeSumBST(root.right,L,R)
        elif root.val <= L and root.val <= R:
            return self.rangeSumBST(root.right,L,R)
        else:
            return self.rangeSumBST(root.left,L,R)
    