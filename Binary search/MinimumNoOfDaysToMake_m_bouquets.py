class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if len(bloomDay) < m*k:
            return -1
        l = min(bloomDay)
        r = max(bloomDay)
        while l < r:
            mid = l + (r-l)//2
            if self.fun(bloomDay,mid,k,m) < m:
                l = mid + 1
            else:
                r = mid
        return l
            
    def fun(self,bloomDay,mid,k,m):
        adj, count = 0, 0
        for i in range(len(bloomDay)):
            if bloomDay[i] > mid:
                adj = 0
            else:
                adj += 1
                if adj == k:
                    adj = 0
                    count += 1
                if count >= m:
                    break
        return count