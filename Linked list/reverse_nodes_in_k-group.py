"""Given a linked list, reverse the nodes of a linked list k at 
a time and return its modified list.
k is a positive integer and is less than or equal to the length 
of the linked list. If the number of nodes is not a multiple of k 
then left-out nodes in the end should remain as it is."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head and not head.next:
            return head
        st = []
        curr = head
        sam = ListNode(0)
        temp = sam
        while curr:
            for i in range(k):
                st.append(curr)
                curr = curr.next
                if not curr:
                    break
            if len(st) == k:
                while st:
                    temp.next = st.pop()
                    temp = temp.next
            else:
                while st:
                    temp.next = st.pop(0)
                    temp = temp.next
        temp.next = None
        return sam.next
            
