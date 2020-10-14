# Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
"""Given inorder and postorder traversal of a tree, construct the binary tree."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def buildTree(self, inorder, postorder):
        return self.helper(len(postorder)-1,0,len(inorder)-1,postorder,inorder)
    
    def helper(self,poststart,instart,inend,postorder,inorder):
        if poststart < 0 or instart > inend:
            return 
        node = TreeNode(postorder[poststart])
        for i in range(len(inorder)):
            if inorder[i] == node.val:
                index = i
                break
        node.right = self.helper(poststart-1,index+1,inend,postorder,inorder)
        node.left = self.helper(poststart - (inend-index+1),instart,index-1,postorder,inorder)
        return node