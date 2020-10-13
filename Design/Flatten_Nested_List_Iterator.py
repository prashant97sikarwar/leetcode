# Problem Link :- https://leetcode.com/problems/flatten-nested-list-iterator/

"""Given a nested list of integers, implement an iterator to flatten it.Each element is 
either an integer, or a list -- whose elements may also be integers or other lists."""
# Input: [[1,1],2,[1,1]]
# Output: [1,1,2,1,1]

class NestedIterator(object):

    def __init__(self, nestedList):
        self.ans = []
        self.helper(nestedList)
        
    def helper(self,nestedList):
        for x in nestedList:
            if not x.isInteger():
                self.helper(x.getList())
            else:
                self.ans.append(x.getInteger())

    def next(self):
         return self.ans.pop(0)
        

    def hasNext(self):
        return len(self.ans) > 0