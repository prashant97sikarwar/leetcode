#Problem Link:- https://leetcode.com/problems/design-front-middle-back-queue/

"""Design a queue that supports push and pop operations in the front, middle, and back."""

class FrontMiddleBackQueue:
    import math
    def __init__(self):
        self.arr = []
        

    def pushFront(self, val: int) -> None:
        self.arr.insert(0,val)

    def pushMiddle(self, val: int) -> None:
        n = len(self.arr) + 1
        if n %2 == 1:
            ind = len(self.arr)//2
        else:
            ind = n//2 - 1
        self.arr.insert(ind,val)
        

    def pushBack(self, val: int) -> None:
        self.arr.append(val)
        

    def popFront(self) -> int:
        return self.arr.pop(0) if len(self.arr) > 0 else -1
        

    def popMiddle(self) -> int:
        n = len(self.arr) 
        if n %2 == 1:
            ind = len(self.arr)//2
        else:
            ind = n//2 - 1
        return self.arr.pop(ind) if len(self.arr) > 0 else -1
        

    def popBack(self) -> int:
        return self.arr.pop() if len(self.arr) > 0 else -1
        


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()