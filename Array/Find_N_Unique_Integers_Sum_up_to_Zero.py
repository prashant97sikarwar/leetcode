#Problem link:- https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

"""Given an integer n, return any array containing n unique integers such that they 
add up to 0."""

class Solution:
    def sumZero(self, n: int) -> List[int]:
        l = []
        for i in range(n-1):
            l.append(i+1)
        sm =  (n-1)*n//2
        l.append(-sm)
        return l