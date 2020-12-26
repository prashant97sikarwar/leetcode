#Problem Link:- https://leetcode.com/problems/design-circular-queue/

"""Design your implementation of the circular queue. The circular queue is a linear data 
structure in which the operations are performed based on FIFO (First In First Out) 
principle and the last position is connected back to the first position to make a 
circle. It is also called "Ring Buffer".One of the benefits of the circular queue is 
that we can make use of the spaces in front of the queue. In a normal queue, once the 
queue becomes full, we cannot insert the next element even if there is a space in front 
of the queue. But using the circular queue, we can use the space to store new values."""

class MyCircularQueue:

    def __init__(self, k: int):
        self.arr = []
        self.size = 0
        self.k = k
        

    def enQueue(self, value: int) -> bool:
        if self.size < self.k:
            self.arr.append(value)
            self.size += 1
            return True
        

    def deQueue(self) -> bool:
        if self.size > 0:
            self.arr.pop(0)
            self.size -= 1
            return True
        

    def Front(self) -> int:
        if self.size > 0:
            return self.arr[0]
        return -1
        

    def Rear(self) -> int:
        if self.size > 0:
            return self.arr[-1]
        return -1
        

    def isEmpty(self) -> bool:
        if self.size == 0:
            return True
        return False
        

    def isFull(self) -> bool:
        if self.size == self.k:
            return True
        return False
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()