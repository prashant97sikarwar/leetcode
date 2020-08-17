"""You are given two non-empty linked lists representing two non-negative 
integers. The digits are stored in reverse order and each of their nodes 
contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except 
the number 0 itself."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
        
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur1 = l1
        cur2 = l2
        head = ListNode(0)
        temp = head
        dep = 0
        while cur1 is not None and cur2 is not None:
            sm = cur1.val + cur2.val + dep
            if sm < 10:
                temp.next = ListNode(sm)
                temp = temp.next
                dep = 0
            else:
                fr = sm%10
                temp.next = ListNode(fr)
                temp = temp.next
                dep = 1
            cur1 = cur1.next
            cur2 = cur2.next
        while cur1 is not None:
            sm = dep + cur1.val
            if sm > 9:
                fr  = sm%10
                temp.next = ListNode(fr)
                temp = temp.next
                dep =1
            else:
                temp.next = ListNode(sm)
                temp = temp.next
                dep = 0
            cur1 = cur1.next
        
        while cur2 is not None:
            sm = dep + cur2.val
            if sm > 9:
                fr  = sm%10
                temp.next = ListNode(fr)
                temp = temp.next
                dep =1
            else:
                temp.next = ListNode(sm)
                temp = temp.next
                dep = 0
            cur2 = cur2.next
        if dep == 1:
            temp.next = ListNode(dep)
        return head.next
            