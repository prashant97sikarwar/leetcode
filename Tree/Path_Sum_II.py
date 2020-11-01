# Problem Link :- https://leetcode.com/problems/path-sum-ii/

"""Given a binary tree and a sum, find all root-to-leaf paths where each path's 
sum equals the given sum."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root, sum):
        ans = []
        
        def helper(root,total,res):
            if root:
                if not root.left and not root.right:
                    if total + root.val == sum:
                        ans.append(res + [root.val])
                        return 
                helper(root.left,total + root.val,res + [root.val])
                helper(root.right,total + root.val,res + [root.val])
        helper(root,0,[])
        return ans
