#Problem link:- https://leetcode.com/problems/minimum-distance-between-bst-nodes/
"""Given a Binary Search Tree (BST) with the root node root, return the minimum 
difference between the values of any two different nodes in the tree"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def minDiffInBST(self, root):
        if root is None:
            return 
        ans = []
        self.traverse(root,ans)
        diff = 100000
        for i in range(len(ans)-1):
            diff = min(diff,ans[i+1]-ans[i])
        return diff
        
    def traverse(self,root,ans):
        if root is None:
            return 
        self.traverse(root.left,ans)
        ans.append(root.val)
        self.traverse(root.right,ans)
        