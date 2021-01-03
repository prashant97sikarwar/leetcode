#Problem Link:- https://leetcode.com/problems/implement-stack-using-queues/

"""Implement a last in first out (LIFO) stack using only two queues. The implemented stack 
should support all the functions of a normal queue (push, top, pop, and empty)."""

class MyStack(object):

    def __init__(self):
        self.first = []
        self.second = []

    def push(self, x):
        self.first.append(x)
        

    def pop(self):
        while len(self.first) > 1:
            self.second.append(self.first.pop(0))
        ans = self.first.pop()
        while len(self.second) > 0:
            self.first.append(self.second.pop(0))
        return ans

    def top(self):
        if len(self.first) > 0:
            return self.first[-1]
        

    def empty(self):
        return True if len(self.first) == 0 else False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()