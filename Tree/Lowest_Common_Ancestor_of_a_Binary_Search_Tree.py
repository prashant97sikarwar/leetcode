# Problem Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

"""Given a binary search tree (BST), find the lowest common ancestor (LCA) 
of two given nodes in the BST."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        while root:
            if root.val > p.val and root.val > q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else:
                return root
        return 