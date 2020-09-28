class Solution(object):
    def isIdealPermutation(self, A):
        if len(A) == 0 or len(A) == 1 or (len(A) == 2 and A[0] < A[1]):
            return True
        tmp = A[0]
        for i in range(2, len(A)):
            if tmp > A[i] :
                return False
            tmp = max(tmp, A[i-1])
        return True
