#Problem Link:- https://leetcode.com/problems/implement-queue-using-stacks/submissions/

"""Implement a first in first out (FIFO) queue using only two stacks. The implemented queue 
should support all the functions of a normal queue (push, peek, pop, and empty)."""

class MyQueue(object):

    def __init__(self):
        self.first = []
        self.second = []
        

    def push(self, x):
        self.first.append(x)
        

    def pop(self):
        if len(self.first) == 1:
            return self.first.pop()
        else:
            while len(self.first) > 0:
                self.second.append(self.first.pop())
        ans = self.second.pop()
        while len(self.second) > 0:
            self.first.append(self.second.pop())
        return ans

    def peek(self):
        return self.first[0]

    def empty(self):
        return True if len(self.first) == 0 else False
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()