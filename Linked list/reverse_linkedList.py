"""Reverse a singly linked list."""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return 
        if head.next is None:
            return head
        prev = None
        curr = head
        nxt = curr.next
        while curr is not None:
            curr.next = prev
            prev = curr
            curr = nxt
            if nxt:
                nxt = nxt.next
        return prev
        