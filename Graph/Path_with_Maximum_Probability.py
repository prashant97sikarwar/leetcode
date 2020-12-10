#Problem Link:- https://leetcode.com/problems/path-with-maximum-probability/

"""You are given an undirected weighted graph of n nodes (0-indexed), represented by an 
edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with 
a probability of success of traversing that edge succProb[i].Given two nodes start and 
end, find the path with the maximum probability of success to go from start to end and 
return its success probability.If there is no path from start to end, return 0. Your 
answer will be accepted if it differs from the correct answer by at most 1e-5."""

class Solution(object):
    def maxProbability(self, n, edges, succProb, start, end):
        from collections import defaultdict
        graph = defaultdict(list)
        prob = dict()
        for i in range(len(edges)):
            u,v = edges[i]
            graph[u].append(v)
            graph[v].append(u)
            prob[(u,v)] = succProb[i]
            prob[(v,u)] = succProb[i]
        res = 0
        queue = [(-1,start)]
        dic = defaultdict(float)
        while queue:
            p,u = heapq.heappop(queue)
            p = -p
            if u == end:
                res = max(res,p)
            for v in graph[u]:
                curp = p * prob[(u,v)]
                if curp > dic[v]:
                    dic[v] = curp
                    heapq.heappush(queue,(-curp,v))
        return res
            