#Problem Link:- https://leetcode.com/problems/validate-stack-sequences/

"""Given two sequences pushed and popped with distinct values, return true if and only if 
this could have been the result of a sequence of push and pop operations on an initially 
empty stack."""

class Solution(object):
    def validateStackSequences(self, pushed, popped):
        st = [1001]
        left = 0
        n = len(popped)
        for i in range(len(pushed)):
            if len(st) == 0 or st[-1] != popped[left]:
                st.append(pushed[i])
            while st and left < n and st[-1] == popped[left]:
                st.pop()
                left += 1 
        while st and left < n and st[-1] == popped[left]:
            st.pop()
            left += 1
        if left == n:
            return True
        return False