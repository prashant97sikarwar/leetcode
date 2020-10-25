# Problem Link :- https://leetcode.com/problems/average-of-levels-in-binary-tree/

"""Given a non-empty binary tree, return the average value of the nodes 
on each level in the form of an array. """

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def averageOfLevels(self, root):
        if root is None:
            return 
        que = [root]
        ans = []
        while que:
            count = len(que)
            num = len(que)
            sm = 0
            while count > 0:
                temp = que.pop(0)
                sm += temp.val
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
            ans.append(sm/num)
        return ans
        