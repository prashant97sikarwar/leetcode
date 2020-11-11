#Problem Link:- https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

"""Given the root of a binary tree, the depth of each node is the shortest distance to 
the root.Return the smallest subtree such that it contains all the deepest nodes in the 
original tree.A node is called the deepest if it has the largest depth possible among 
any node in the entire tree"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
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