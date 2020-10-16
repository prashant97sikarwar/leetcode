#Problem Link :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

"""Given a binary tree, return the zigzag level order traversal of its nodes' values."""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def zigzagLevelOrder(self, root):
        if root is None:
            return 
        que = [root]
        ans = []
        level = 1
        while len(que) > 0:
            cnt = len(que)
            res = []
            while cnt > 0:
                temp = que.pop(0)
                res.append(temp.val)
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                cnt -= 1
            if level%2 == 1:
                ans.append(res)
            else:
                ans.append(res[::-1])
            level += 1
        return ans
            
        