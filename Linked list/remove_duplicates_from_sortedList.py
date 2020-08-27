"""Given a sorted linked list, delete all duplicates 
such that each element appear only once."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
         
         
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return
        curr = head
        while curr.next is not None:
            temp = curr.next
            if curr.val == curr.next.val:
                curr.next = temp.next
            else:
                curr = curr.next
        return head