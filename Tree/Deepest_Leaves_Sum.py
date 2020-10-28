# Problem Link :- https://leetcode.com/problems/deepest-leaves-sum/

"""Given a binary tree, return the sum of values of its deepest leaves. """

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deepestLeavesSum(self, root):
        if root is None:
            return 
        que = [root]
        while que:
            count = len(que)
            sm = 0
            for x in que:
                sm += x.val
            while count > 0:
                temp = que.pop(0)
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
        return sm