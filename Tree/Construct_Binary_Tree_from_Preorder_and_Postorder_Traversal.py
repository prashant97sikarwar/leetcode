#Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

"""Return any binary tree that matches the given preorder and postorder traversals.
Values in the traversals pre and post are distinct positive integers."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructFromPrePost(self, pre,post):
        if not pre:
            return 
        root = TreeNode(pre[0])
        if len(pre) == 1:
            return root
        L = post.index(pre[1]) + 1
        root.left = self.constructFromPrePost(pre[1:L+1],post[:L])
        root.right = self.constructFromPrePost(pre[L+1:],post[L:-1])
        return root