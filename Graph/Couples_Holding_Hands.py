#Problem link;- https://leetcode.com/problems/couples-holding-hands/

""" N couples sit in 2N seats arranged in a row and want to hold hands. We want to know 
the minimum number of swaps so that every couple is sitting side by side. A swap consists 
of choosing any two people, then they stand up and switch seats.The people and seats are 
represented by an integer from 0 to 2N-1, the couples are numbered in order, the first 
couple being (0, 1), the second couple being (2, 3), and so on with the last couple being 
(2N-2, 2N-1).The couples' initial seating is given by row[i] being the value of the person 
who is initially sitting in the i-th seat. """

class helper(object):
    def __init__(self,row):
        self.roots = dict()
        for x in row:
            if x%2 == 0:
                self.roots[x] = x
            else:
                self.roots[x] = x-1
    
    def union(self,u,v):
        p = self.find(u)
        q = self.find(v)
        if p == q:
            return 
        else:
            self.roots[p] = q
            
    def find(self,u):
        if self.roots[u] == u:
            return u
        self.roots[u] = self.find(self.roots[u])
        return self.roots[u]
    
    def disjoint_sets(self):
        return (len(set(self.find(p) for p in self.roots)))

class Solution(object):
    def minSwapsCouples(self, row):
        n = len(row)
        dsuf = helper(row)
        
        for i in range(0, n, 2):
            dsuf.union(row[i], row[i+1])
        
        disjoint_sets = dsuf.disjoint_sets()
        return n/2 - disjoint_sets