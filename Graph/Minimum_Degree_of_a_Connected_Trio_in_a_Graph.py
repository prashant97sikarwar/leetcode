#Problem link:- https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

"""You are given an undirected graph. You are given an integer n which is the number of nodes in 
the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected 
edge between ui and vi.A connected trio is a set of three nodes where there is an edge between 
every pair of them.The degree of a connected trio is the number of edges where one endpoint is in 
the trio, and the other is not.Return the minimum degree of a connected trio in the graph, or -1 
if the graph has no connected trios."""

class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        from collections import defaultdict
        degree = defaultdict(int)
        graph = defaultdict(set)
        for u,v in edges:
            graph[min(u,v)].add(max(v,u))
            degree[u] += 1
            degree[v] += 1
        ans = float("inf")

        for n1 in range(1,n+1):
            for n2 in graph[n1]:
                for n3 in graph[n1]:
                    if n3 in graph[n2]:
                        ans = min(ans,degree[n1] + degree[n2] + degree[n3] - 6)
        return ans if ans < float("inf") else -1