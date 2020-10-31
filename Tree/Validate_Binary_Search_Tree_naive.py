# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    ## function to check whether the Tree is binary search tree or not.
    
    def isValidBST(self, root):
        ans = []
        self.inorder(root,ans)
        for i in range(len(ans)-1):
            if ans[i+1] <= ans[i]:
                return False
        return True
        
    ## function to perform the inorder traversal of the Tree 
    
    def inorder(self,root,ans):
        if root is None:
            return []
        self.inorder(root.left,ans)
        ans.append(root.val)
        self.inorder(root.right,ans)
        