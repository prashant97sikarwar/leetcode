#Problem Link :- https://leetcode.com/problems/n-ary-tree-level-order-traversal/

"""Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, 
each group of children is separated by the null value """


# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root):
        if root is None:
            return 
        que = [root]
        ans = []
        while que:
            count = len(que)
            res = []
            while count > 0:
                temp = que.pop(0)
                res.append(temp.val)
                for x in temp.children:
                    que.append(x)
                count -= 1
            ans.append(res)
        return ans
                
        