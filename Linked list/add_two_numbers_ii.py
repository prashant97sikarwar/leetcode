"""You are given two non-empty linked lists representing two non-negative 
integers. The most significant digit comes first and each of their nodes 
contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the 
number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the 
lists is not allowed. """

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
         
         
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None and l2 is None:
            return 0
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        temp = ListNode(0)
        head = temp
        st1 =  []
        st2 = []
        st3 = []
        while l1 is not None:
            st1.append(l1)
            l1 = l1.next
        while l2 is not None:
            st2.append(l2)
            l2 = l2.next
        dep = 0
        while st1 and st2:
            sm = st1.pop().val + st2.pop().val + dep
            if sm > 9:
                fr = sm%10
                st3.append(fr)
                dep = 1
            else:
                st3.append(sm)
                dep = 0
        while st1:
            sm = dep + st1.pop().val
            if sm > 9:
                fr = sm %10
                st3.append(fr)
                dep = 1
            else:
                st3.append(sm)
                dep = 0
        while st2:
            sm = dep + st2.pop().val
            if sm > 9:
                fr = sm %10
                st3.append(fr)
                dep = 1
            else:
                st3.append(sm)
                dep = 0
        if dep == 1:
            st3.append(dep)
        while st3:
            temp.next = ListNode(st3.pop())
            temp = temp.next
        return head.next