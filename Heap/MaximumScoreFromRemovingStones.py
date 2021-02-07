#Problem Link:- https://leetcode.com/problems/maximum-score-from-removing-stones/

"""You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ r
espectively. Each turn you choose two different non-empty piles, take one stone from 
each, and add 1 point to your score. The game stops when there are fewer than two non-
empty piles.Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get."""

class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        import heapq
        heap = [-a,-b,-c]
        sm = 0
        while True:
            first = heappop(heap)
            sec = heappop(heap)
            if first == 0 or sec == 0:
                break
            sm += 1
            first = -(abs(first) -1)
            sec = -(abs(sec)-1)
            heappush(heap,first)
            heappush(heap,sec)
        return sm