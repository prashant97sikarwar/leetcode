"""Merge two sorted linked lists and return it as 
a new sorted list. The new list should be made by splicing 
together the nodes of the first two lists."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        sam = head
        while l1 is not None and l2 is not None:
            if l1.val <= l2.val:
                head.next = l1
                head = head.next
                l1 = l1.next
            else:
                head.next = l2
                head = head.next
                l2 = l2.next
        while l1 is not None:
            head.next = l1
            l1 = l1.next
            head = head.next
        while l2 is not None:
            head.next = l2
            l2 = l2.next
            head = head.next
        return sam.next