"""Given a (singly) linked list with head node root, write a function to split 
the linked list into k consecutive linked list "parts".
The length of each part should be as equal as possible: no two parts should have 
a size differing by more than 1. This may lead to some parts being null.
The parts should be in order of occurrence in the input list, and parts 
occurring earlier should always have a size greater than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts that are formed. """


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
         
         
class Solution:
    def splitListToParts(self, root: ListNode, k: int):
        curr = root
        length = 0
        while curr is not None:
            length += 1
            curr = curr.next
        width,extra = divmod(length,k)
        ans = []
        curr = root
        for i in range(k):
            head = curr
            for j in range(width + (i < extra) -1):
                if curr:
                    curr =  curr.next
            if curr:
                temp = curr.next
                curr.next = None
                curr = temp
            ans.append(head)
        return ans