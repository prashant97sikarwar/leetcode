# Problem Link :- https://leetcode.com/problems/odd-even-linked-list/

"""Given a singly linked list, group all odd nodes together 
followed by the even nodes. Please note here we are talking 
about the node number and not the value in the nodes.
You should try to do it in place. The program should 
run in O(1) space complexity and O(nodes) time complexity."""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
            self.val = val
            self.next = next
            
        
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None:
            return 
        odd = head
        even = odd.next
        ebeg = odd.next
        while odd.next and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        odd.next = ebeg
        return head