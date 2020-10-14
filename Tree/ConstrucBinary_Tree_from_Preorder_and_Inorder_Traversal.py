# Problem Link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

"""Given preorder and inorder traversal of a tree, construct the binary tree."""
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def buildTree(self, preorder, inorder):
        return self.helper(0,0,len(inorder)-1,preorder,inorder)
    
    def helper(self,prestart,instart,inend,preorder,inorder):
        if prestart > len(preorder) - 1 or instart > inend:
            return 
        node = TreeNode(preorder[prestart])
        for i in range(len(inorder)):
            if inorder[i] == node.val:
                index = i
                break
        node.left = self.helper(prestart+1,instart,index-1,preorder,inorder)
        node.right = self.helper(prestart+index-instart+1,index+1,inend,preorder,inorder)
        return node