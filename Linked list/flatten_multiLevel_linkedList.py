"""You are given a doubly linked list which in addition to the 
next and previous pointers, it could have a child pointer, 
which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own,and so on,
to produce a multilevel data structure, as shown in the example below.
Flatten the list so that all the nodes appear in a single-level, 
doubly linked list. You are given the head of the first level of the list."""


# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        temp = head
        stack = []
        while head:
            if head.child:
                if head.next:
                    stack.append(head.next)
                head.next = head.child
                head.next.prev = head
                head.child = None
            elif not head.next and stack:
                head.next = stack.pop()
                head.next.prev = head
            head = head.next
        return temp
                