#Problem Link:- https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
"""There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way 
to travel between two different cities.Roads are represented by connections where 
connections[i] = [a, b] represents a road from city a to b.Roads are represented by 
connections where connections[i] = [a, b] represents a road from city a to b.Your task 
consists of reorienting some roads such that each city can visit the city 0. Return the 
minimum number of edges changed."""

class Solution:
    def minReorder(self, n: int, connections):
        from collections import defaultdict
        graph = defaultdict(list)
        for i,j in connections:
            graph[i].append((j,1))
            graph[j].append((i,0))
        self.ans = 0
        visited = [False] * n
        self.dfs(0,graph,visited)
        return self.ans
    
    def dfs(self,node,graph,visited):
        if visited[node] == True:
            return 
        visited[node] = True
        for nei,val in graph[node]:
            if visited[nei] == False:
                self.ans += val
                self.dfs(nei,graph,visited)