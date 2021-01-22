#Problem Link:- https://leetcode.com/problems/jump-game-v/

"""Given an array of integers arr and an integer d. In one step you can jump from index i 
to index:i + x where: i + x < arr.length and 0 < x <= d.i - x where: i - x >= 0 and 0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] 
for all indices k between i and j (More formally min(i, j) < k < max(i, j)).You can choose any
index of the array and start jumping. Return the maximum number of indices you can visit."""

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        from collections import defaultdict
        n = len(arr)
        graph = defaultdict(list)
        
        for i in range(n):
            for j in range(1,d+1):
                if (i+j) < n:
                    if arr[i] > arr[i+j]:
                        graph[i].append(i+j)
                    else:
                        break
        for i in range(n):
            for j in range(1,d+1):
                if (i-j) >= 0:
                    if arr[i] > arr[i-j]:
                        graph[i].append(i-j)
                    else:
                        break
        memo = {}
        def dfs(node):
            if node in memo:
                return memo[node]
            dist = 1
            for x in graph[node]:
                dist = max(dist,dfs(x) + 1)
            memo[node] = dist
            return dist
        for i in range(n):
            dfs(i)
        return max(memo.values())
        
        