# Problem Link:- https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

"""here is an undirected weighted connected graph. You are given a positive integer n which denotes 
that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] 
denotes that there is an edge between nodes ui and vi with weight equal to weighti.A path from node 
start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end 
and there is an edge between zi and zi+1 where 0 <= i <= k-1.The distance of a path is the sum of 
the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a 
path between node n and node x. A restricted path is a path that also satisfies that 
distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.Return the number of 
restricted paths from node 1 to node n. Since that number may be too large, return it modulo 
109 + 7."""

class Solution(object):
    def countRestrictedPaths(self, n, edges):
        import heapq
        from collections import defaultdict
        graph = defaultdict(set)
        for u,v,w in edges:
            graph[u-1].add((v-1,w))
            graph[v-1].add((u-1,w))
        distance = self.helper(graph,n-1,n)
        memo = dict()
        return self.answer(graph,distance,0,memo)
        
    def answer(self,graph,distance,node,memo):
        n = len(graph)
        MOD = 10**9 + 7
        if node == n-1:
            return 1
        if node in memo:
            return memo[node]
        ans = 0
        for nei, w in graph[node]:
            if distance[node] > distance[nei]:
                ans += (self.answer(graph,distance,nei,memo)) % MOD
        memo[node] = ans % MOD
        return memo[node]
        
        
    def helper(self,graph,source, n):
        pq = [(0,source)]
        distance = [float("inf")] * n
        vis = [False] * n
        distance[source] = 0
        while pq:
            d, node = heappop(pq)
            vis[node] = True
            for nei, wei in graph[node]:
                if not vis[nei]:
                    dist = d + wei
                    if dist < distance[nei]:
                        distance[nei] = dist
                        heappush(pq,(dist,nei))
        return distance