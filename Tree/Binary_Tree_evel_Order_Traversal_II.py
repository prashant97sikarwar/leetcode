# Problem Link :- https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

"""Given a binary tree, return the bottom-up level order traversal of its nodes' 
values. (ie, from left to right, level by level from leaf to root)."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrderBottom(self, root):
        ans =[] 
        if root is None:
            return
        else:
            que = []
            que.append(root)
            while que:
                l = []
                count = len(que)
                while count > 0:
                    kj = que.pop(0)
                    l.append(kj.val)
                    if kj.left is not None:
                        que.append(kj.left)
                    if kj.right is not None:
                        que.append(kj.right)
                    count -= 1
                ans.append(l)
        pq = ans[::-1]
        return pq