# Problem Link :- https://leetcode.com/problems/n-ary-tree-preorder-traversal/

"""Given an n-ary tree, return the preorder traversal of its nodes' values.Nary-Tree input 
serialization is represented in their level order traversal, each group of children is separated 
by the null value (See examples)."""


# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        if not root:
            return []
        ans = []
        ans.append(root.val)
        for x in root.children:
            ans += self.preorder(x)
        return ans
        