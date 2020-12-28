#Problem Link:- https://leetcode.com/problems/grumpy-bookstore-owner/

"""Today, the bookstore owner has a store open for customers.length minutes.  Every 
minute, some number of customers (customers[i]) enter the store, and all those customers 
leave after the end of that minute.On some minutes, the bookstore owner is grumpy.  If 
the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.
When the bookstore owner is grumpy, the customers of that minute are not satisfied, 
otherwise they are satisfied.The bookstore owner knows a secret technique to keep 
themselves not grumpy for X minutes straight, but can only use it once.
Return the maximum number of customers that can be satisfied throughout the day."""

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        n = len(customers)
        sm = 0
        for i in range(n):
            if grumpy[i] == 0:
                sm += customers[i]
        left = 0
        ans = 0
        for i in range(n):
            if grumpy[i] == 1:
                sm += customers[i]
            while (left < n and (i-left+1) > X):
                if grumpy[left] == 1:
                    sm -= customers[left]
                left += 1
            ans = max(ans,sm)
        return ans