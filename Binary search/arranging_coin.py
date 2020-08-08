class Solution:
    def arrangeCoins(self, n: int) -> int:
        i = 0
        j = n
        while i <= j:
            dep =  (i+j)//2
            ps  =  dep*(dep +1)//2
            if ps <= n:
                ans  = dep
                i = dep +1
            else:
                j = dep-1
        return ans