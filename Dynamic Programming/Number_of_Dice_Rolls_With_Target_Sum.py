#Problem Link :- https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

"""You have d dice, and each die has f faces numbered 1, 2, ..., f.
Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 
to roll the dice so the sum of the face up numbers equals target."""

class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if d*f < target: 
            return 0        
        elif d*f == target: 
            return 1     
        mod = 1000000007
        dp = [[0] * (target+1) for _ in range(d+1)] 
        for j in range(1, min(f+1, target+1)): 
            dp[1][j] = 1
        for i in range(2, d+1):
            for j in range(1, target+1):
                for k in range(1, f+1):
                    if j - k >= 0: 
                        dp[i][j] += dp[i-1][j-k]
                        dp[i][j] %= mod        
        return dp[-1][-1] 