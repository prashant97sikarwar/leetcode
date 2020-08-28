"""Given an array of distinct integers arr, find all pairs of elements 
with the minimum absolute difference of any two elements. 
Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
a, b are from arr, a < b, b - a equals to the minimum absolute difference 
of any two elements in arr
"""


class Solution(object):
    def minimumAbsDifference(self, arr):
        n = len(arr)
        arr.sort()
        mn = 1000001
        for i in range(n-1):
            mn = min(mn,abs(arr[i+1] - arr[i]))
        l = []
        for i in range(n-1):
            if abs(arr[i+1] - arr[i]) == mn:
                l.append([arr[i],arr[i+1]])
        return l