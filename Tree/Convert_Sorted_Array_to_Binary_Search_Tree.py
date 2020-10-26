# Problem Link :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

"""Given an array where elements are sorted in ascending order, convert it to a height balanced 
BST.For this problem, a height-balanced binary tree is defined as a binary tree in which the 
depth of the two subtrees of every node never differ by more than 1."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums):
        if len(nums) == 0:
            return None
        else:
            mid = len(nums)//2
            root = TreeNode(nums[mid])
            root.left = self.sortedArrayToBST(nums[:mid])
            root.right = self.sortedArrayToBST(nums[mid+1:])
        return root
        