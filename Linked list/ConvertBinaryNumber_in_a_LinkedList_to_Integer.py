#Problem Link:- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

"""Given head which is a reference node to a singly-linked list. The value of each node in the 
linked list is either 0 or 1. The linked list holds the binary representation of a number.Return 
the decimal value of the number in the linked list."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        curr = head
        sm = 0
        while curr is not None:
            if curr.val == 1:
                sm = sm * 2 + 1
            if curr.val == 0:
                sm *= 2
            curr = curr.next
        return sm