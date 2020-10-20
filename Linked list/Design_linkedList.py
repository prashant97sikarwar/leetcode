# Problem Link :- https://leetcode.com/problems/design-linked-list/

class Node:
    def __init__(self,val, next=None):
        self.val = val
        self.next = next

class MyLinkedList(object):

    def __init__(self,head=None):
        self.head = head
        self.length = 0
        

    def get(self, index):
        if index >= self.length:
            return -1
        count = 0
        cur = self.head
        while count != index:
            cur =  cur.next
            count += 1
        return cur.val
        
    def addAtHead(self, val):
        new =  Node(val)
        new.next = self.head
        self.head = new
        self.length = self.length + 1

    def addAtTail(self, val):
        new = Node(val)
        if self.head is None:
            self.head = new
            self.length += 1
            return
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = new
        self.length += 1
        
    def addAtIndex(self, index, val):
        new = Node(val)
        if index > self.length:
            return 
        if index == 0:
            new.next = self.head
            self.head = new
            self.length += 1
            return 
        cur = self.head
        count = 0
        while count != index-1:
            cur = cur.next
            count += 1
        temp = cur.next
        cur.next = new
        new.next = temp
        self.length += 1
        return

    def deleteAtIndex(self, index):
        if index >= self.length:
            return 
        if index == 0:
            temp = self.head
            self.head = temp.next
            return 
        if index == self.length-1:
            cur = self.head
            while cur.next.next is not None:
                cur =  cur.next
            cur.next = None
            self.length -= 1
            return 
        count = 0
        cur = self.head
        while count != index:
            cur = cur.next
            count += 1
        nxt = cur.next
        temp = nxt.next
        cur.val = nxt.val
        cur.next = temp
        self.length -= 1
        return 
