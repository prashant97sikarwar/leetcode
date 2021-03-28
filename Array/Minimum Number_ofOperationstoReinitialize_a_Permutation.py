# Problem Link:- https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

"""You are given an even integer n​​​​​​. You initially have a permutation perm of size n​​ where 
perm[i] == i​ (0-indexed)​​​​.
In one operation, you will create a new array arr, and for each i:
1.If i % 2 == 0, then arr[i] = perm[i / 2].
2.If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].
You will then assign arr​​​​ to perm.Return the minimum non-zero number of operations you need to 
perform on perm to return the permutation to its initial value."""

class Solution:
    def reinitializePermutation(self, n: int) -> int:
        arr = [0 for i in range(n)]
        perm = [i for i in range(n)]
        drt = [i for i in range(n)]
        cnt = 0
        while arr != drt:
            for i in range(n):
                if i % 2 == 0:
                    arr[i] = perm[i//2]
                else:
                    arr[i] = perm[n//2 + (i-1)//2]
            perm = [arr[i] for i in range(n)]
            cnt += 1
        return cnt