# Problem Link :- https://leetcode.com/problems/binary-tree-level-order-traversal/

"""Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).""" 

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution(object):
    def levelOrder(self, root):
        import collections
        if root is None:
            return
        nodes = collections.defaultdict(list)
        return self.helper(root,1,nodes).values()
        
    def helper(self,root,level,nodes):
        nodes[level].append(root.val)
        if root.left:
            self.helper(root.left,level+1,nodes)
        if root.right:
            self.helper(root.right,level+1,nodes)
        return nodes
        