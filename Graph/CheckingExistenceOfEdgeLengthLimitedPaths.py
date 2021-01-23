#Problem Link:- https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

"""An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] 
denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple 
edges between two nodes.Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for 
each queries[j] whether there is a path between pj and qj such that each edge on the path 
has a distance strictly less than limitj.Return a boolean array answer, where 
answer.length == queries.length and the jth value of answer is true if there is a path 
for queries[j] is true, and false otherwise."""

class DSU:
    def __init__(self,n):
        self.parent = [i for i in range(n+1)]
        self.size = [1 for i in range(n+1)]
    
    def find(self,u):
        if self.parent[u] == u:
            return u
        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
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
    def distanceLimitedPathsExist(self, n, edgeList, queries):
        edgeList.sort(key = lambda x: x[2])
        dsu = DSU(n)
        q = [(l,u,v,i) for i,(u,v,l) in enumerate(queries)]
        q.sort()
        m = len(queries)
        ans = [False] * m
        edge_size = len(edgeList)
        edge_index = 0
        for q_limit,u,v,i in q:
            while edge_index < edge_size and edgeList[edge_index][2] < q_limit:
                first = edgeList[edge_index][0]
                sec = edgeList[edge_index][1]
                dsu.union(first,sec)
                edge_index += 1
            x = dsu.find(u)
            y = dsu.find(v)
            if x == y:
                ans[i] = True
        return ans