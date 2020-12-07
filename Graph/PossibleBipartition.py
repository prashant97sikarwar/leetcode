#Problem Link ;- https://leetcode.com/problems/possible-bipartition/

"""Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into 
two groups of any size.Each person may dislike some other people, and they should not go 
into the same group. Formally, if dislikes[i] = [a, b], it means it is not allowed to put 
the people numbered a and b into the same group.Return true if and only if it is possible 
to split everyone into two groups in this way."""

class Solution(object):
    def possibleBipartition(self, N, dislikes):
        from collections import defaultdict
        graph = defaultdict(list)
        for u,v in dislikes:
            graph[u].append(v)
            graph[v].append(u)
        vis = [0 for i in range(N+1)]
        color = [2 for i in range(N+1)]
        for i in range(1,N+1):
            if vis[i] == 0 and color[i] == 2:
                if self.dfs(i,vis,color,0,graph) == False:
                    return False
        return True
                
            
    def dfs(self,node,vis,color,cur,graph):
        vis[node] = 1
        color[node] = cur
        for x in graph[node]:
            if vis[x] == 0:
                if self.dfs(x,vis,color,cur^1,graph) == False:
                    return False
            else:
                if color[x] == color[node]:
                    return False
        return True