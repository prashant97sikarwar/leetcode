#Problem Link:- https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

"""Given a binary tree root, a ZigZag path for a binary tree is defined as follow:
Choose any node in the binary tree and a direction (right or left).If the current 
direction is right then move to the right child of the current node otherwise move 
to the left child.Change the direction from right to left or right to left.Repeat the 
second and third step until you can't move in the tree.Zigzag length is defined as 
the number of nodes visited - 1. (A single node has a length of 0).Return the longest 
ZigZag path contained in that tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        self.ans = 0
        def helper(root):
            if not root:
                return [-1,-1]
            l1,r1 = helper(root.left)
            l2,r2 = helper(root.right)
            self.ans =  max(self.ans,max(r1+1,l2+1))
            return [r1+1,l2+1] 
        helper(root)
        return self.ans
            