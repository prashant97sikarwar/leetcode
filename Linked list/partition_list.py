"""Given a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in 
each of the two partitions."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        temp1 = ListNode(0)
        sam1 = temp1
        temp2 = ListNode(0)
        sam = temp2
        while head:
            if head.val < x:
                temp1.next = ListNode(head.val)
                temp1 = temp1.next
            else:
                temp2.next = ListNode(head.val)
                temp2 = temp2.next
            head = head.next
        temp1.next = sam.next
        return sam1.next