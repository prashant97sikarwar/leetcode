"""Given a linked list, swap every two adjacent nodes 
and return its head.You may not modify the values in the 
list's nodes, only nodes itself may be changed."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        temp = head.next.next
        head,head.next = head.next, head
        head.next.next = None
        node = self.swap(temp)
        head.next.next = node
        return head
        
        
    def swap(self,head):
        if not head:
            return 
        if not head.next:
            return head
        temp = head.next.next
        head,head.next = head.next, head
        head.next.next = None
        node = self.swap(temp)
        head.next.next = node
        return head
        