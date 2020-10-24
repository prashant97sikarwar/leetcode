# Problem Link:- https://leetcode.com/problems/n-ary-tree-postorder-traversal/

"""Given an n-ary tree, return the postorder traversal of its nodes' values."""


# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def postorder(self, root):
        if root is None:
            return []
        ans = []
        level = []
        level.append(root)
        while level:
            temp = level.pop()
            ans.append(temp.val)
            for x in temp.children:
                level.append(x)
        return ans[::-1]
        