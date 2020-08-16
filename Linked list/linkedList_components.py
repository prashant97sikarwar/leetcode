"""We are given head, the head node of a linked list containing unique integer values.
We are also given the list G, a subset of the values in the linked list.
Return the number of connected components in G, where two values are 
connected if they appear consecutively in the linked list"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
         
         
class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        if head is None:
            return 
        curr = head
        parent =  None
        ans = 0
        while curr:
            if parent is None:
                if curr.val in G:
                    ans += 1
            else:
                if parent.val not in G and curr.val in G:
                    ans += 1
            parent = curr
            curr = curr.next
        return ans