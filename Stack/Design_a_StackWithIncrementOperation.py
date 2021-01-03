#Problem Link :- https://leetcode.com/problems/design-a-stack-with-increment-operation/

"""Design a stack which supports the following operations.
Implement the CustomStack class:
-> CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number 
    of elements in the stack or do nothing if the stack reached the maxSize.
-> void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
-> int pop() Pops and returns the top of stack or -1 if the stack is empty.
-> void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are 
    less than k elements in the stack, just increment all the elements in the stack.
"""
class CustomStack:

    def __init__(self, maxSize: int):
        self.arr = []
        self.maxSize = maxSize
        self.size = 0
        
        

    def push(self, x: int) -> None:
        if self.size < self.maxSize:
            self.arr.append(x)
            self.size += 1

    def pop(self) -> int:
        if self.size > 0:
            self.size -= 1
            return self.arr.pop(self.size)
        return -1
        

    def increment(self, k: int, val: int) -> None:
        if self.size <= k:
            for i in range(self.size):
                self.arr[i] += val
        else:
            for i in range(k):
                self.arr[i] += val
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)