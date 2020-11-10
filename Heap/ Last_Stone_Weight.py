#Problem Link :- https://leetcode.com/problems/last-stone-weight/

"""We have a collection of stones, each stone has a positive integer weight.Each turn, we 
choose the two heaviest stones and smash them together.  Suppose the stones have weights 
x and y with x <= y.  The result of this smash is:If x == y, both stones are totally 
destroyed;If x != y, the stone of weight x is totally destroyed, and the stone of weight 
y has new weight y-x.At the end, there is at most 1 stone left.  Return the weight of 
this stone (or 0 if there are no stones left.)"""

class Solution:
    def lastStoneWeight(self, stones):
        import heapq
        stones = [-x for x in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            stones1 = -(heapq.heappop(stones))
            stones2 = -(heapq.heappop(stones))
            if stones1 == stones2:
                continue
            else:
                heapq.heappush(stones,-abs(stones1-stones2))
        if len(stones) == 0:
            return 0
        else:
            return -(heapq.heappop(stones))
                