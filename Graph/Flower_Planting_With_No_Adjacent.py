#Problem Link:- https://leetcode.com/problems/flower-planting-with-no-adjacent/

"""you have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] 
describes a bidirectional path between garden xi to garden yi. In each garden, you want
to plant one of 4 types of flowers.All gardens have at most 3 paths coming into or 
leaving it.Your task is to choose a flower type for each garden such that, for any two 
gardens connected by a path, they have different types of flowers.Return any such a 
choice as an array answer, where answer[i] is the type of flower planted in the 
(i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer 
exists."""

class Solution:
    def gardenNoAdj(self, N: int, paths):
        from collections import defaultdict
        graph = defaultdict(list)
        for i in range(len(paths)):
            graph[paths[i][0]].append(paths[i][1])
            graph[paths[i][1]].append(paths[i][0])
        arr = [None] * N
        for i in range(1,N+1):
            color = set([1,2,3,4])
            for node in graph[i]:
                if arr[node-1] in color:
                    color.discard(arr[node-1])
            arr[i-1] = color.pop()
        return arr
            