#Problem Link :- https://leetcode.com/problems/jump-game-iii/

"""Given an array of non-negative integers arr, you are initially positioned at start 
index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], 
check if you can reach to any index with value 0.Notice that you can not jump outside 
of the array at any time."""

class Solution(object):
    def canReach(self, arr, start):
        from collections import defaultdict
        graph = defaultdict(list)
        n = len(arr)
        dest = []
        def safe(x,y):
            if x < 0 or x > n-1 or y < 0 or y > n-1:
                return False
            return True

        for i in range(n):
            if safe(i,i-arr[i]) == True:
                graph[i].append(i-arr[i])
            if safe(i,i+arr[i]) == True:
                graph[i].append(i+arr[i])
                
        vis = [0 for i in range(n)]
        
        que = []
        que.append(start)
        vis[start] = 1
        if arr[start] == 0:
            return True
        while que:
            node = que.pop(0)
            for x in graph[node]:
                if vis[x] == 0:
                    que.append(x)
                    vis[x] = 1
                    if arr[x] == 0:
                        return True
        return False