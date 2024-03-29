#Problem Link : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

"""On a 2D plane, we place stones at some integer coordinate points.  Each coordinate 
point may have at most one stone.Now, a move consists of removing a stone that shares 
a column or row with another stone on the grid.What is the largest possible number of 
moves we can make?"""

class DSU:
    def __init__(self, N):
        self.p = range(N)

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution(object):
    def removeStones(self, stones):
        N = len(stones)
        dsu = DSU(20000)
        for x, y in stones:
            dsu.union(x, y + 10000)

        return N - len({dsu.find(x) for x, y in stones})