#Problem Link : https://leetcode.com/problems/jump-game-iv/

"""Given an array of integers arr, you are initially positioned at the first index of 
the array.In one step you can jump from index i to index:i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.j where: arr[i] == arr[j] and i != j.Return the minimum number 
of steps to reach the last index of the array."""

class Solution:
    def minJumps(self, arr: List[int]) -> int:
        from collections import defaultdict
        n = len(arr)
        if n <= 1:
            return 0
        index = defaultdict(list)
        for i in range(len(arr)):
            index[arr[i]].append(i)
        que = [0]
        vis = {0}
        dist = 0
        while que:
            nxt = []
            for node in que:
                if node == n-1:
                    return dist
                for child in index[arr[node]]:
                    if child not in vis:
                        vis.add(child)
                        nxt.append(child)
                index[arr[node]].clear()
                for child in [node-1,node+1]:
                    if 0 <= child < n and child not in vis:
                        vis.add(child)
                        nxt.append(child)
            que = nxt
            dist += 1
        return -1