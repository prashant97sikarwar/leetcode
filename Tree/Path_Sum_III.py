#Problem Link :- https://leetcode.com/problems/path-sum-iii/

"""You are given a binary tree in which each node contains an integer value.Find the 
number of paths that sum to a given value.The path does not need to start or end at 
the root or a leaf, but it must go downwards (traveling only from parent nodes to 
child nodes)."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        d = dict()
        d[0] = 1
        self.count = 0
        def helper(root,ps):
            if root is None:
                return 0
            cs = ps + root.val
            x = cs - sum
            if x in d:
                self.count += d[x]
            if cs in d:
                d[cs] += 1
            else:
                d[cs] = 1
            helper(root.left,cs)
            helper(root.right,cs)
            d[cs] -= 1
        helper(root,0)
        return self.count
            
            