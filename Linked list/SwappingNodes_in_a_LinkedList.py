#Problelm Link:- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

"""You are given the head of a linked list, and an integer k.Return the head of the linked 
list after swapping the values of the kth node from the beginning and the kth node from the 
end"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapNodes(self, head: ListNode, k: int) -> ListNode:
        if head.next == None:
            return head
        slow,fast = head,head
        for i in range(k-1):
            fast = fast.next
        first = fast
        while fast.next:
            fast = fast.next
            slow =  slow.next
        second = slow
        first.val, second.val = second.val,first.val
        return head