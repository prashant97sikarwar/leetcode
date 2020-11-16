#Problem Link:- https://leetcode.com/problems/even-odd-tree/

"""A binary tree is named Even-Odd if it meets the following conditions:The root of the 
binary tree is at level index 0, its children are at level index 1, their children are 
at level index 2, etc.For every even-indexed level, all nodes at the level have odd integer 
values in strictly increasing order (from left to right).For every odd-indexed level, all 
nodes at the level have even integer values in strictly decreasing order (from left to 
right).Given the root of a binary tree, return true if the binary tree is Even-Odd, 
otherwise return false."""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if root is None:
            return 
        que = [root]
        level = 0
        while que:
            count = len(que)
            if level % 2 == 0:
                prev = None
                for i in range(len(que)):
                    if que[i].val % 2 == 1 and prev == None:
                        prev = que[i].val
                    elif que[i].val % 2 == 1 and prev != None:
                        if que[i].val <= prev:
                            return False
                        else:
                            prev = que[i].val
                    else:
                        return False
            elif level % 2 == 1:
                prev = None
                for i in range(len(que)):
                    if que[i].val % 2  == 0 and prev == None:
                        prev = que[i].val
                    elif que[i].val % 2 == 0 and prev != None:
                        if que[i].val >= prev:
                            return False
                        else:
                            prev = que[i].val
                    else:
                        return False
            while count > 0:
                temp = que.pop(0)
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
            level += 1
        return True
            