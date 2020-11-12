#Problem Link:- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/

"""Given the root of a binary tree, the level of its root is 1, the level of its 
children is 2, and so on.Return the smallest level X such that the sum of all the 
values of nodes at level X is maximal."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if root is None:
            return 
        que = [root]
        depth = 1
        mxsum = float("-inf")
        while que:
            count = len(que)
            sm = 0
            while count > 0:
                temp = que.pop(0)
                sm+=temp.val
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
            if sm > mxsum:
                mxsum = sm
                ans = [depth,mxsum]
            depth += 1
        return ans[0]
                