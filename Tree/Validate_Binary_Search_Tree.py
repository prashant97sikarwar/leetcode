# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root):
        mx = 4294967296
        mn = -4294967296
        return self.helper(root,mn,mx)
    
    ## helper function to check node's values are in their specified ranges
    def helper(self,root,mn,mx):
        if root is None:
            return True
        if (root.val > mx) or (root.val < mn):
            return False
        left = self.helper(root.left,mn,root.val-1)       
        right = self.helper(root.right,root.val+1,mx)
        return left and right
    
