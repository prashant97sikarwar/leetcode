"""A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.
Return a deep copy of the list."""


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head :
            return 
        d = dict()
        curr = head
        while curr is not None:
            d[curr] = Node(curr.val)
            curr = curr.next
        curr = head
        while curr is not None:
            temp = d[curr]
            if curr.next not in d:
                temp.next = None
            if curr.next in d:
                temp.next = d[curr.next]
            if curr.random not in d:
                temp.random = None
            if curr.random in d:
                temp.random = d[curr.random]
            temp = temp.next
            curr = curr.next
        return d[head]
            