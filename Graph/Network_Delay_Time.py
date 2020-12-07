#problem Link :- https://leetcode.com/problems/network-delay-time/

"""There are N network nodes, labelled 1 to N.Given times, a list of travel times as 
directed edges times[i] = (u, v, w), where u is the source node, v is the target node, 
and w is the time it takes for a signal to travel from source to target.Now, we send a 
signal from a certain node K. How long will it take for all nodes to receive the signal? 
If it is impossible, return -1."""

class Solution(object):
    from collections import heapq
    def networkDelayTime(self, times, N, K):
        from collections import defaultdict
        graph = defaultdict(list)
        for u,v,w in times:
            graph[u].append((v,w))
        
        pq = [(0,K)]
        dist = {}
        while pq:
            d,node = heappop(pq)
            if node in dist:
                continue
            dist[node] = d
            for nei,d2 in graph[node]:
                if nei not in dist:
                    heapq.heappush(pq,(d+d2,nei))
        return max(dist.values()) if len(dist) == N else -1
            