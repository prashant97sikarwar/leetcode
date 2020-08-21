"""Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.
Return the linked list sorted as well."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        prev = sam = ListNode(next=head)
        curr = head
        while curr is not None and curr.next:
            temp = curr.next
            if temp.val == curr.val:
                while temp is not None and temp.val == curr.val:
                    temp = temp.next
                prev.next = temp
                curr = temp
            else:
                prev = prev.next
                curr = curr.next
        return sam.next