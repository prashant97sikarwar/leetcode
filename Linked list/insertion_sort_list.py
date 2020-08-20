"""Sort a linked list using insertion sort."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head: return None
        if not head.next: return head
        
        dummy = ListNode(None,head)
        current = head
        
        while current.next is not None:
            if current.next.val >= current.val:
                current = current.next     
            else: 
                temp = current.next
                runner = dummy
                current.next = current.next.next
                while runner.next.val <= temp.val:
                    runner = runner.next
                runner.next, temp.next = temp, runner.next
                
        return dummy.next   
                