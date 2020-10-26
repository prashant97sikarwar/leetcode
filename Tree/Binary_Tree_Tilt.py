# Problem Link :- https://leetcode.com/problems/binary-tree-tilt/

"""Given the root of a binary tree, return the sum of every tree node's tilt.The tilt of 
a tree node is the absolute difference between the sum of all left subtree node values and 
all right subtree node values. If a node does not have a left child, then the sum of the left 
subtree node values is treated as 0. The rule is similar if there the node does not have a 
right child"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findTilt(self, root):
        total_tilt = 0

        def valueSum(node):
            nonlocal total_tilt

            if not node:
                return 0

            left_sum = valueSum(node.left)
            right_sum = valueSum(node.right)
            tilt = abs(left_sum - right_sum)
            total_tilt += tilt

            return left_sum + right_sum + node.val

        valueSum(root)

        return total_tilt