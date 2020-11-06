# Problem Link :- https://leetcode.com/problems/maximum-width-of-binary-tree/

"""Given a binary tree, write a function to get the maximum width of the given tree. 
The maximum width of a tree is the maximum width among all levels."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        from collections import defaultdict
        d = defaultdict(list)
        if root is None:
            return 
        self.helper(root,d,0,1)
        return max(x[-1] - x[0]+1 for x in d.values())
        
        
    def helper(self,root,d,level,indx):
        if root:
            d[level].append(indx)
            self.helper(root.left,d,level+1,2*indx-1)
            self.helper(root.right,d,level+1,2*indx)

