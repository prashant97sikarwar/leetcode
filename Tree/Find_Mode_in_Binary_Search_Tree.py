# Problem Link:- https://leetcode.com/problems/find-mode-in-binary-search-tree/

"""Given a binary search tree (BST) with duplicates, find all the mode(s) 
(the most frequently occurred element) in the given BST."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findMode(self, root):
        if root is None:
            return 
        que = [root]
        d = dict()
        while que:
            temp = que.pop(0)
            if temp.left:
                que.append(temp.left)
            if temp.right:
                que.append(temp.right)
            if temp.val not in d:
                d[temp.val] = 1
            if temp.val in d:
                d[temp.val] += 1
        mxfreq = max(d.values())
        ans = []
        for x in d:
            if d[x] == mxfreq:
                ans.append(x)
        return ans 