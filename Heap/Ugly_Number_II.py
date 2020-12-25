#Problem Link:-https://leetcode.com/problems/ugly-number-ii/

"""Write a program to find the n-th ugly number.Ugly numbers are positive numbers whose 
prime factors only include 2, 3, 5. """

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        import heapq
        heap = [1]
        nums = []
        seen = set()
        for i in range(n):
            curr_ugly = heapq.heappop(heap)
            nums.append(curr_ugly)
            for x in [2,3,5]:
                new = curr_ugly * x
                if new not in seen:
                    seen.add(new)
                    heapq.heappush(heap,new)
        return nums[-1]
