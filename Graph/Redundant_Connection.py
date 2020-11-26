#Problem Link:- https://leetcode.com/problems/redundant-connection/

""" The given input is a graph that started as a tree with N nodes (with distinct values 1, 2,
..., N), with one additional edge added. The added edge has two different vertices chosen 
from 1 to N, and was not an edge that already existed.The resulting graph is given as a 
2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an 
undirected edge connecting nodes u and v.Return an edge that can be removed so that the 
resulting graph is a tree of N nodes. If there are multiple answers, return the answer 
that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, 
with u < v."""

class Solution(object):
    def findRedundantConnection(self, edges):
        parent = [-1 for i in range(len(edges)+1)]
        ans = [None,None]
        for i,j in edges:
            first = self.find(parent,i)
            second = self.find(parent,j)
            if first == second:
                ans = [i,j]
            else:
                self.union(first,second,parent)
        return ans
        
        
    def find(self,parent,x):
        if parent[x] == -1:
            return x
        return self.find(parent,parent[x])
    
    def union(self,x,y,parent):
        x_pa = self.find(parent,x)
        y_pa = self.find(parent,y)
        parent[x_pa] = y_pa
        