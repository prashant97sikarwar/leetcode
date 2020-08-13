"""Given head which is a reference node to a singly-linked list.
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list."""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        curr = head
        l = []
        while curr is not None:
            l.append(curr.val)
            curr = curr.next
        sm = 0
        for i in range(len(l)):
            if l[len(l)-i-1] == 1:
                sm += (1 << i)
        return sm