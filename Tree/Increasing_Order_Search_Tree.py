# Problem Link :- https://leetcode.com/problems/increasing-order-search-tree/

"""Given a binary search tree, rearrange the tree in in-order so that the 
leftmost node in the tree is now the root of the tree, and every node has no 
left child and only 1 right child."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def increasingBST(self, root):
        curr = root
        stack = []
        ans = []
        while (True):
            if curr is not None:
                stack.append(curr)
                curr = curr.left
            elif len(stack) > 0:
                curr = stack.pop(-1)
                ans.append(curr.val)
                curr = curr.right
            else:
                break
        root1 = TreeNode(ans[0])
        dep = root1
        for j in range(1,len(ans)):
            root1.right = TreeNode(ans[j])
            root1 = root1.right
        return dep