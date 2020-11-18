#Problem Link:- https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
"""Given two binary trees original and cloned and given a reference to a node target in the 
original tree.The cloned tree is a copy of the original tree.Return a reference to the same 
node in the cloned tree."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if cloned:
            if cloned.val == target.val:
                return cloned
            else:
                return self.getTargetCopy(original,cloned.left,target) or self.getTargetCopy(original,cloned.right,target)