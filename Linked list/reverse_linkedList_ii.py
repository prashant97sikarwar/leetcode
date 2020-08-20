"""Reverse a linked list from position m to n. Do it in one-pass."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if not head and not head.next:
            return head
        start = pre = ListNode(next=head)
        for i in range(m-1):
            pre = pre.next
        prev,nxt = self.reverse(pre.next,n-m+1)
        pre.next.next = nxt
        pre.next = prev
        return start.next
        
        
    def reverse(self,st,count):
        prev = None
        while count > 0:
            q = st.next
            st.next = prev
            prev = st
            st = q
            count -= 1
        return prev, st
        