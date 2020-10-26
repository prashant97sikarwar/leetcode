# Problem Link :- https://leetcode.com/problems/diameter-of-binary-tree/ 

"""Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes 
in a tree. This path may or may not pass through the root"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 1
        def depth(root):
            if not root:
                return 0
            lh = depth(root.left)
            rh = depth(root.right)
            self.ans = max(self.ans,lh+rh+1)
            return max(lh,rh) + 1
        depth(root)
        return self.ans - 1