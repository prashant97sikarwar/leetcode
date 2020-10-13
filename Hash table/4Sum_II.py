# Problem Link :- https://leetcode.com/problems/4sum-ii/

"""Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) 
there are such that A[i] + B[j] + C[k] + D[l] is zero."""

class Solution:
    def fourSumCount(self, A, B, C, D):
        d = {}
        count = 0
        for i in A:
            for j in B:
                df = i + j
                if df not in d:
                    d[df] = 1
                else:
                    d[df] += 1
        for i in C:
            for j in D:
                tar = 0 - (i+j)
                if tar in d:
                    count += d[tar]
        return count