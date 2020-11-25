#Problem Link:- https://leetcode.com/problems/maximal-network-rank/

'''There is an infrastructure of n cities with some number of roads connecting these cities. 
Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected 
roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of 
different cities.Given the integer n and the array roads, return the maximal network rank 
of the entire infrastructure.'''

class Solution(object):
    def maximalNetworkRank(self, n, roads):
        mat = [[0 for i in range(n)] for j in range(n)]
        for i,j in roads:
            mat[i][j] = 1
            mat[j][i] = 1
        d = dict()
        for i in range(n):
            c = 0
            for j in range(n):
                if mat[i][j] ==1:
                    c += 1
            d[i] = c
        lst = sorted(d.items(),key = lambda x:x[1],reverse = True)
        mx = 0
        for i in range(len(lst)):
            first = lst[i][1]
            first_node = lst[i][0]
            for j in range(i+1,len(lst)):
                ans = first + lst[j][1]
                if mat[first_node][lst[j][0]] == 1:
                    ans -= 1
                mx = max(mx,ans)
        return mx
        