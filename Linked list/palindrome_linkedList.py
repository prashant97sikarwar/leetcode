"""Given a singly linked list, determine if it is a palindrome."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        l = []
        if head is None:
            return True
        if head.next is None:
            return True
        if head.next.next is None:
            if head.val == head.next.val:
                return True
            else:
                return False
        slow = head
        fast = head
        cnt = 0
        while head is not None:
            cnt += 1
            head =  head.next
        while slow and fast and fast.next:
            l.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        if cnt % 2 == 1:
            slow  = slow.next
        for i in range(len(l)-1,-1,-1):
            if l[i] != slow.val:
                return False
            slow = slow.next
        return True

            
        