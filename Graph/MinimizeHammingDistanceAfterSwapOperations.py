#Problem Link:- https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/

"""You are given two integer arrays, source and target, both of length n. You are also given
an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed 
to swap the elements at index ai and index bi (0-indexed) of array source. Note that you 
can swap elements at a specific pair of indices multiple times and in any order.
The Hamming distance of two arrays of the same length, source and target, is the number of 
positions where the elements are different. Formally, it is the number of indices i for 
0 <= i <= n-1 where source[i] != target[i] (0-indexed).Return the minimum Hamming distance 
of source and target after performing any amount of swap operations on array source."""

class disjointSet:
    def __init__(self,n):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]
        
    def find(self,v):
        if self.parent[v] == v:
            return v
        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]
    
    def union(self,u,v):
        x = self.find(u)
        y = self.find(v)
        if x == y:
            return
        else:
            if self.size[x] > self.size[y]:
                self.parent[y] = x
                self.size[x] += self.size[y]
            else:
                self.parent[x] = y
                self.size[y] += self.size[x]

class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        from collections import defaultdict
        n = len(source)
        ds = disjointSet(n)
        for u,v in allowedSwaps:
            ds.union(u,v)
        m = defaultdict(set)
        for i in range(n):
            m[ds.find(i)].add(i)
        res = 0
        for indices in m.values():
            freq = {}
            for i in indices:
                freq[source[i]] = freq.get(source[i], 0)+1
                freq[target[i]] = freq.get(target[i],0) - 1
            res += sum(val for val in freq.values() if val > 0)
        return res
        
        
        