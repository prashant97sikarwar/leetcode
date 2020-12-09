#Problem Link :- https://leetcode.com/problems/redundant-connection-ii/

""" The given input is a directed graph that started as a rooted tree with N nodes (with 
distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has
two different vertices chosen from 1 to N, and was not an edge that already existed.The 
resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] 
that represents a directed edge connecting nodes u and v, where u is a parent of child v.
Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array."""

class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        parent = [-1 for i in range(len(edges)+1)]
        cana, canb = None, None
        check = {}
        for u,v in edges:
            if v not in check:
                check[v] = u
            else:
                canb = [u,v]
                cana = [check[v],v]
        
        for u,v in edges:
            if [u,v] == canb:
                continue
            if self.union(u,v,parent) == False:
                if cana:
                    return cana
                else:
                    return [u,v]
        return canb
        
    def find(self,x,parent):
        if parent[x] == -1:
            return x
        return self.find(parent[x],parent)
    
    def union(self,x,y,parent):
        a = self.find(x,parent)
        b = self.find(y,parent)
        if a == b:
            return False
        parent[a] = b