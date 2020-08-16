"""We are given a linked list with head as the first node.  
Let's number the nodes in the list: node_1, node_2, node_3, ... etc.

Each node may have a next larger value: for node_i, next_larger(node_i) 
is the node_j.val such that j > i, node_j.val > node_i.val, and j is 
the smallest possible choice.  If such a j does not exist, 
the next larger value is 0."""




# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        if head is None:
            return 
        from collections import defaultdict
        d = {}
        d  = defaultdict(lambda:0,d)
        cur = head
        st = []
        while cur is not None:
            while st and st[-1].val < cur.val:
                d[st.pop()] = cur.val
            st.append(cur)
            cur = cur.next
        l = []
        while head:
            l.append(d[head])
            head = head.next
        return l