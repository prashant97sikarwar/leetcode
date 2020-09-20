"""A sequence of numbers is called arithmetic if it consists of at least three 
elements and if the difference between any two consecutive elements is the same.
A zero-indexed array A consisting of N numbers is given. A slice of that array is 
any pair of integers (P, Q) such that 0 <= P < Q < N.A slice (P, Q) of the array A 
is called arithmetic if the sequence:A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. 
In particular, this means that P + 1 < Q.The function should return the number of 
arithmetic slices in the array A."""


class Solution(object):
    def numberOfArithmeticSlices(self, A):
        n = len(A)
        cnt = 0
        res = 0
        for i in range(2,n):
            if A[i] - A[i-1] == A[i-1] - A[i-2]:
                cnt += 1
                res += cnt
            else:
                cnt = 0
        return res