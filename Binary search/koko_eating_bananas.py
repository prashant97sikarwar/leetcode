class Solution:
    import math
    def minEatingSpeed(self, piles, H ): 
        if H == len(piles):
            return max(piles)
        l = 1
        r = max(piles)
        while l < r:
            mid = l + (r-l)//2
            if self.check(piles,mid) > H:
                l = mid + 1
            else:
                r = mid
        return l
            
    def check(self,piles,mid):
        sm = 0
        for i in range(len(piles)):
            sm += math.ceil(piles[i]/mid)
        return sm