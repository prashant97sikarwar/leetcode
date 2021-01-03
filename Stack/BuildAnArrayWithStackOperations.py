#Problem Link:- https://leetcode.com/problems/build-an-array-with-stack-operations/

"""Given an array target and an integer n. In each iteration, you will read a number from  
list = {1,2,3..., n}.Build the target array using the following operations:Push: Read a new 
element from the beginning list, and push it in the array.Pop: delete the last element of the 
array.If the target array is already built, stop reading more elements.Return the operations 
to build the target array. You are guaranteed that the answer is unique."""

class Solution(object):
    def buildArray(self, target, n):
        s = set(target)
        ans = []
        for i in range(1,target[-1]+1):
            if i in s:
                ans.append("Push")
            else:
                ans.append("Push")
                ans.append("Pop")
        return ans