#Problem Link:- https://leetcode.com/problems/maximum-binary-tree/

""" Given an integer array with no duplicates. A maximum tree building on this array 
is defined as follow:The root is the maximum number in the array.The left subtree is 
the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided 
by the maximum number.Construct the maximum tree by the given array and output the 
root node of this tree. """

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructMaximumBinaryTree(self, nums) -> TreeNode:
        def make_tree(nums):
            if len(nums) == 0: return None
            max_index = nums.index(max(nums))
            root = TreeNode(nums[max_index])

            left_list = nums[:max_index]
            right_list = nums[max_index+1:]

            root.left = make_tree(left_list)
            root.right = make_tree(right_list)

            return root

        return make_tree(nums)