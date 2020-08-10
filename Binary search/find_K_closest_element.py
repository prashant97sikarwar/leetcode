class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        import bisect
        if len(arr) == 0:
            return []
        if x <= arr[0]:
            return arr[:k]
        if x >= arr[-1]:
            return arr[-k:]
        else:
            ind = bisect.bisect_left(arr,x)
            low = max(0,ind - k-1)
            high = min(len(arr)-1,ind+k-1)
            while True:
                if high - low+1 == k:
                    return arr[low:high+1]
                d1 = abs(arr[low] - x)
                d2 = abs(arr[high] - x)
                if d1 <= d2:
                    high -=1
                else:
                    low += 1
