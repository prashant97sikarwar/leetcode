# Problem Link :- https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

"""Populate each next pointer to point to its next right node. If there is no next 
right node, the next pointer should be set to NULL."""

# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return 
        que = [root]
        while que:
            count = len(que)
            while count > 0:
                temp = que.pop(0)
                if count == 1:
                    temp.next = None
                if count > 1:
                    temp.next = que[0]
                if temp.left:
                    que.append(temp.left)
                if temp.right:
                    que.append(temp.right)
                count -= 1
        return root
        
