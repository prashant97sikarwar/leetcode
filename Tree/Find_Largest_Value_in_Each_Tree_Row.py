# Problem Link:- https://leetcode.com/problems/find-largest-value-in-each-tree-row/

"""Given the root of a binary tree, return an array of the largest value in each 
row of the tree (0-indexed)."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: TreeNode):
        if root is None:
            return 
        que = [root]
        ans = []
        while que:
            count = len(que)
            mx = float("-inf")
            while count > 0:
                temp = que.pop(0)
                mx = max(temp.val,mx)
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
            ans.append(mx)
        return ans