# Problem Link :- 

"""You are given a perfect binary tree where all leaves are on the same level, and every 
parent has two children.Populate each next pointer to point to its next right node. If there 
is no next right node, the next pointer should be set to NULL.Initially, all next pointers are 
set to NULL."""


# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution(object):
    def connect(self, root):
        if root is None:
            return 
        que = []
        que.append(root)
        while que:
            count = len(que)
            while count > 0:
                temp = que.pop(0)
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                if count == 1:
                    temp.next = None
                if count > 1:
                    temp.next = que[0]
                count -= 1
        return root
                
        