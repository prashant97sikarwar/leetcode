"""Write a program to find the node at which the intersection 
of two singly linked lists begins."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        cura = headA
        curb = headB
        if headA is None or headB is None:
            return 
        la = 0
        lb = 0
        while headA:
            la += 1
            headA = headA.next
        while headB:
            lb += 1
            headB = headB.next
        if la >= lb:
            temp = cura
            sm = curb
        else:
            temp = curb
            sm = cura
        cnt = 0
        diff = abs(la-lb)
        while cnt < diff:
            temp = temp.next
            cnt += 1
        while sm and temp:
            if sm == temp:
                return sm
            sm = sm.next
            temp = temp.next
        
        