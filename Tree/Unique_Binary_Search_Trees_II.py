# Problem Link :- https://leetcode.com/problems/unique-binary-search-trees-ii/

"""Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n."""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n):
        if n == 0:
            return []
        return self.helper(1,n+1)
    
    def helper(self,start,end):
        if start >= end:
            return [None]
        ans = []
        for i in range(start,end):
            left = self.helper(start,i)
            right = self.helper(i+1,end)
            for l in left:
                for r in right:
                    node = TreeNode(i)
                    node.left = l
                    node.right = r
                    ans.append(node)
        return ans
