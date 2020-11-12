#Problem Link:- https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

"""Return the root node of a binary search tree that matches the given 
preorder traversal."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def bstFromPreorder(self, preorder):
        if len(preorder) == 0:
            return 
        inorder = sorted(preorder)
        return self.helper(0,0,len(inorder)-1,inorder,preorder)
        
    def helper(self,preStart,inStart,inEnd,inorder,preorder):
        if (preStart > len(preorder)-1) or (inStart > inEnd):
            return 
        root = TreeNode(preorder[preStart])
        for i in range(len(inorder)):
            if root.val == inorder[i]:
                index = i
                break
        root.left = self.helper(preStart+1,inStart,index-1,inorder,preorder)
        root.right = self.helper(preStart+index-inStart+1,index+1,inEnd,inorder,preorder)
        return root