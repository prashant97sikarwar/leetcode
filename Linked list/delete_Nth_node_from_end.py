"""Given a linked list, remove the n-th node 
from the end of list and return its head."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head is None:
            return 
        curr = head
        while n > 0 and curr:
            curr = curr.next
            n -= 1
        temp = head
        prev = None
        if curr is None:
            head = temp.next
            return head
        while curr is not None:
            curr = curr.next
            prev = temp
            temp = temp.next
        fr = temp.next
        prev.next = fr
        return head
        
        