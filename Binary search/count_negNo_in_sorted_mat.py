class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        sm = 0
        for arr in grid:
            l = 0
            r = len(arr)
            if arr[0] < 0:
                sm += r
            elif arr[r-1] >= 0:
                continue
            else:
                while l < r:
                    mid = (l+r)//2
                    if arr[mid] < 0:
                        r = mid
                    else:
                        l = mid + 1
                sm += (len(arr)-r)
        return sm