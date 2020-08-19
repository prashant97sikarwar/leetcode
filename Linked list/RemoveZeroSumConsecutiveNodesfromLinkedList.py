"""Given the head of a linked list, we repeatedly delete consecutive sequences 
of nodes that sum to 0 until there are no such sequences.
After doing so, return the head of the final linked list.  
You may return any such answer."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        d = dict()
        curr = head
        dummy = ListNode(0)
        dummy.next = head
        psm = 0
        d[psm] = dummy
        while head:
            psm += head.val
            if psm in d:
                to_remove = d[psm].next
                sm = psm
                while to_remove != head:
                    sm += to_remove.val
                    d.pop(sm)
                    to_remove = to_remove.next
                d[psm].next = head.next
            else:
                d[psm] = head
            head = head.next
        return dummy.next