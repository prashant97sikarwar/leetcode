#Problem Link:- https://leetcode.com/problems/number-of-operations-to-make-network-connected/

"""here are n computers numbered from 0 to n-1 connected by ethernet cables connections 
forming a network where connections[i] = [a, b] represents a connection between computers 
a and b. Any computer can reach any other computer directly or indirectly through the 
network.Given an initial computer network connections. You can extract certain cables 
between two directly connected computers, and place them between any pair of disconnected 
computers to make them directly connected. Return the minimum number of times you need to 
do this in order to make all the computers connected. If it's not possible, return -1. """

class Solution(object):
    def makeConnected(self, n, connections):
        from collections import defaultdict
        graph = defaultdict(list)
        edges = len(connections)
        for u,v in connections:
            graph[u].append(v)
            graph[v].append(u)
        if edges < n-1:
            return -1
        vis = [0 for i in range(n)]
        def dfs(cur,graph):
            vis[cur] = 1
            for x in graph[cur]:
                if vis[x] == 0:
                    dfs(x,graph)
        cnt = 0
        for i in range(n):
            if vis[i] == 0:
                dfs(i,graph)
                cnt+=1
        return cnt-1