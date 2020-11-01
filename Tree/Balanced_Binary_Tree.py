# Problem link :- https://leetcode.com/problems/balanced-binary-tree/

"""Given a binary tree, determine if it is height-balanced."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root):
        def myfun(root):
            if root is None:
                return 0,True
            else:
                lh,fl = myfun(root.left)
                rh,fr = myfun(root.right)
                
                h = 1 + max(lh,rh)
                f = fl and fr and abs(lh - rh) <= 1
                return (h,f)
        return myfun(root)[1]