"""Given a linked list, return the node where the cycle begins. If there 
is no cycle, return null.To represent a cycle in the given linked list, 
we use an integer pos which represents the position (0-indexed) in the linked 
list where tail connects to. If pos is -1, then there is no cycle in the linked list.
Note: Do not modify the linked list."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return 
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                while head != slow:
                    slow = slow.next
                    head = head.next
                return slow
