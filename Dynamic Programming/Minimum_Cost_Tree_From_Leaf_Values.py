"""Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;The values of arr correspond to the values 
of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf 
if and only if it has 0 children.)The value of each non-leaf node is equal to the 
product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of 
the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer."""

class Solution(object):
    def mctFromLeafValues(self, arr):
        return self.helper(arr,0,len(arr)-1,{})
    
    def helper(self,arr,l,r,dic):
        if l >= r:
            return 0
        if (l,r) in dic:
            return dic[(l,r)]
        res  = float('inf')
        for k in range(l,r):
            rootVal = max(arr[l:k+1]) * max(arr[k+1:r+1])
            res = min(res, rootVal + self.helper(arr,l,k,dic) + self.helper(arr,k+1,r,dic))
        dic[(l,r)] = res
        return res