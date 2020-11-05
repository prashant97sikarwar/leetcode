#Problem Link :- https://leetcode.com/problems/delete-node-in-a-bst/

"""Given a root node reference of a BST and a key, delete the node with the given key 
in the BST. Return the root node reference (possibly updated) of the BST.Basically, the 
deletion can be divided into two stages:Search for a node to remove.If the node is 
found, delete the node."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        if key > root.val:
            root.right = self.deleteNode(root.right,key)
        elif key < root.val:
            root.left = self.deleteNode(root.left,key)
        else:
            if not root.left and not root.right:
                root = None
            elif root.right:
                root.val = self.succesor(root)
                root.right = self.deleteNode(root.right,root.val)
            else:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left,root.val)
        return root
    
    def succesor(self,root):
        root = root.right
        while root.left:
            root = root.left
        return root.val
    
    def predecessor(self,root):
        root = root.left
        while root.right:
            root = root.right
        return root.val
    
