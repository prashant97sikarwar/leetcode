# Problem Link:- https://leetcode.com/problems/univalued-binary-tree/

"""A binary tree is univalued if every node in the tree has the same value.
Return true if and only if the given tree is univalued."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isUnivalTree(self, root):
        if root is None:
            return True
        que = [root]
        check = root.val
        while que:
            temp = que.pop(0)
            if temp.val == check:
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
            else:
                return False
        return True