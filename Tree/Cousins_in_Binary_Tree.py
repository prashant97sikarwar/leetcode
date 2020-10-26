#Problem Link:- https://leetcode.com/problems/cousins-in-binary-tree/

"""In a binary tree, the root node is at depth 0, and children of each depth k node are 
at depth k+1.Two nodes of a binary tree are cousins if they have the same depth, but have 
different parents.We are given the root of a binary tree with unique values, and the 
values x and y of two different nodes in the tree.Return true if and only if the nodes 
corresponding to the values x and y are cousins."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isCousins(self, root, x, y):
        parent = {}
        depth = {}
        q = []
        q.append(root)
        parent[root.val] = 0
        depth[root.val] = 0
        while len(q) > 0:
            f = q.pop(0)
            if f.left:
                q.append(f.left)
                parent[f.left.val] = f.val
                depth[f.left.val] = depth[f.val] + 1
            if f.right:
                q.append(f.right)
                parent[f.right.val] = f.val
                depth[f.right.val] =  depth[f.val] + 1
        if depth[x] == depth[y] and parent[x] != parent[y]:
            return True
        else:
            False
            
                