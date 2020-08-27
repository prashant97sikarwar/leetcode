"""Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an 
integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. If pos is -1, 
then there is no cycle in the linked list."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return 
        slow = head
        fast = head
        while slow is not None and fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False