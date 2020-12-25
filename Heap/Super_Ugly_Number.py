#Problem Link: https://leetcode.com/problems/super-ugly-number/

"""Write a program to find the nth super ugly number.Super ugly numbers are positive 
numbers whose all prime factors are in the given prime list primes of size k."""

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        import heapq
        nums = []
        heap = [1]
        seen = set()
        for i in range(n):
            curr_ugly = heapq.heappop(heap)
            nums.append(curr_ugly)
            for prime in primes:
                new_ugly = curr_ugly*prime
                if new_ugly not in seen:
                    seen.add(new_ugly)
                    heapq.heappush(heap,new_ugly)
        return nums[-1]
