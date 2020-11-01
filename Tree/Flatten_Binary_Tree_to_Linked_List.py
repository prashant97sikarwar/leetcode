# Problem Link :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

"""Given a binary tree, flatten it to a linked list in-place."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root):
        if root is None:
            return 
        st = [root]
        stack = []
        while st:
            temp = st.pop()
            if not temp:
                continue
            stack.append(temp)
            st.append(temp.right)
            st.append(temp.left)
        root = stack.pop(0)
        for x in stack:
            root.right = x
            root.left = None
            root = x
        
        
        