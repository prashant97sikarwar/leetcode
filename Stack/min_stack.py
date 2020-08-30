"""Design a stack that supports push, pop, top, and retrieving the minimum 
element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack."""



class MinStack(object):

    def __init__(self):
        self.stack = []
        self.currMin = float('inf')
        self.prevMin = []
        

    def push(self, x):
        if x <= self.currMin:
            self.prevMin.append(self.currMin)
            self.currMin = x
        self.stack.append(x)
        

    def pop(self):
        if self.stack[-1] == self.currMin:
            self.currMin = self.prevMin.pop()
        self.stack.pop()
        

    def top(self):
        return self.stack[-1]
        

    def getMin(self):
        return self.currMin


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()