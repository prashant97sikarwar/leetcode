# Problem Link:- https://leetcode.com/problems/binary-search-tree-iterator/

"""Implement an iterator over a binary search tree (BST). Your iterator will be 
initialized with the root node of a BST.Calling next() will return the next smallest 
number in the BST."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator:

    def __init__(self, root):
        self.ans = []
        self.helper(root)
        
    def helper(self,root):
        while root:
            self.ans.append(root)
            root = root.left
        

    def next(self) -> int:
        node = self.ans.pop()
        if node.right:
            self.helper(node.right)
        return node.val        

    def hasNext(self) -> bool:
        return True if len(self.ans) > 0 else False


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()