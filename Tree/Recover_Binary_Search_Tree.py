#Problem Link :- https://leetcode.com/problems/recover-binary-search-tree/

"""You are given the root of a binary search tree (BST), where exactly two nodes of the tree 
were swapped by mistake. Recover the tree without changing its structure."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def recoverTree(self, root):
        self.first, self.second, self.prevNode = None, None, None
        self.inOrder(root) 
        self.first.val, self.second.val = self.second.val, self.first.val 

    def inOrder(self, root):
        if not root:
            return
        self.inOrder(root.left)

        if self.prevNode:
            if self.prevNode.val > root.val: 
                if not self.first: 
                    self.first = self.prevNode # Found first pair
                self.second = root

        self.prevNode = root

        self.inOrder(root.right)
