"""Given a linked list, rotate the list to the 
right by k places, where k is non-negative."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next:
            return head
        length = 0
        curr = head
        while curr is not None:
            length += 1
            curr = curr.next
        k = k % length
        if k == 0:
            return head
        slow = head
        while k > 0 and slow:
            slow = slow.next
            k -= 1
        fast = head
        while slow.next is not None:
            slow = slow.next
            fast = fast.next
        sam = fast.next
        fast.next = None
        slow.next = head
        return sam
        
            
        