# Problem Link:- https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

"""Given a n-ary tree, find its maximum depth.The maximum depth is the number of nodes along 
the longest path from the root node down to the farthest leaf node."""

# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution(object):
    def maxDepth(self, root):
        if root is None:
            return 0
        return 1 + max(map(self.maxDepth,root.children)) if root.children else 1