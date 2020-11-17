#Problem Link:- https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

"""Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some 
apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the 
minimum time in seconds you have to spend to collect all apples in the tree, starting at 
vertex 0 and coming back to this vertex.Additionally, there is a boolean array hasApple, 
where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any 
apple."""

class Solution(object):
    def minTime(self, n, edges, hasApple):
        from collections import defaultdict
        graph = defaultdict(list)
        for u,v in edges:
            graph[u].append(v)
            graph[v].append(u)
        visited = [False]*n
        def helper(curr):
            ans = 0
            visited[curr] = True
            for x in graph[curr]:
                if visited[x] == False:
                    ans += helper(x)
            if ans or hasApple[curr]:
                return ans+1
            return 0
        res = helper(0)
        if res == 0:
            return 0
        else:
            return 2*(res-1)
            