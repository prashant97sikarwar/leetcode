"""Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;The values of arr correspond to the values 
of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf 
if and only if it has 0 children.)The value of each non-leaf node is equal to the 
product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of 
the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer."""


class Solution(object):
    def mctFromLeafValues(self, arr):
        res  = 0
        while len(arr) > 1:
            l = 0
            r = 1
            mn = arr[0]*arr[1]
            for i in range(len(arr)-1):
                if arr[i] * arr[i+1] < mn:
                    mn = arr[i]*arr[i+1]
                    l = i
                    r = i+1
            res += mn
            if arr[l] > arr[r]:
                del arr[r]
            else:
                del arr[l]
        return res
