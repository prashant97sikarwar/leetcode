#Problem Link;- https://leetcode.com/problems/is-graph-bipartite/

"""Given an undirected graph, return true if and only if it is bipartite.Recall that a graph 
is bipartite if we can split its set of nodes into two independent subsets A and B, such that 
every edge in the graph has one node in A and another node in B.The graph is given in the 
following form: graph[i] is a list of indexes j for which the edge between nodes i and j 
exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges 
or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice."""

class Solution(object):
    def isBipartite(self, graph):
        visited = [False for i in range(len(graph))]
        color = [2 for i in range(len(graph))]
        
        def dfs(cur,graph,col):
            visited[cur] = True
            color[cur] = col
            for x in graph[cur]:
                if visited[x] == False:
                    if dfs(x,graph,col ^ 1) == False:
                        return False
                else:
                    if color[cur] == color[x]:
                        return False
            return True
        for i in range(len(graph)):
            if visited[i] == False and color[i]== 2:
                if not dfs(i,graph,0):
                    return False
        return True
            