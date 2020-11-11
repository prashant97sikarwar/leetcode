#Problem Link:- https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/submissions/

"""Given the root of a binary tree, return the lowest common ancestor of 
its deepest leaves."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        if root is None:
            return 
        que = [root]
        while que:
            count = len(que)
            check = len(que)
            while count > 0:
                temp = que.pop(0)
                if count == check:
                    first = temp
                if count == 1:
                    second = temp
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
        return self.lca(root,first,second)
    
    def lca(self,root,first,second):
        if root is None:
            return 
        Left = self.lca(root.left,first,second)
        Right = self.lca(root.right,first,second)
        if (Left and Right) or (root in [first,second]):
            return root
        else:
            if Left:
                return Left
            else:
                return Right