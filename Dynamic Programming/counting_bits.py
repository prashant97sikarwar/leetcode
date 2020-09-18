"""Given a non negative integer number num. For every numbers i in the 
range 0 ≤ i ≤ num calculate the number of 1's in their binary representation 
and return them as an array."""


class Solution(object):
    def countBits(self, num):
        dp = [0]
        for i in range(1,num+1):
            if i % 2 == 0:
                dp.append(dp[i//2])
            else:
                dp.append(dp[i-1] + 1)
        return dp