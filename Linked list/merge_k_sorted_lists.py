"""Given an array of linked-lists lists, each linked list 
is sorted in ascending order.
Merge all the linked-lists into one sort linked-list and return it."""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = []
        for node in lists:
            while node:
                heap.append(node.val)
                node = node.next
        heapq.heapify(heap)
        dummy = node = ListNode()
        while heap:
            dummy.next = ListNode(heapq.heappop(heap))
            dummy = dummy.next
        return node.next
            