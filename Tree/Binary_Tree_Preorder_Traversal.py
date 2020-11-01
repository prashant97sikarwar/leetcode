# Problem Link :- https://leetcode.com/problems/binary-tree-preorder-traversal/

"""Given the root of a binary tree, return the preorder traversal of its nodes' values."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root):
        if root is None:
            return 
        st = [root]
        stack = []
        while st:
            temp = st.pop()
            if not temp:
                continue
            stack.append(temp.val)
            st.append(temp.right)
            st.append(temp.left)
        return stack