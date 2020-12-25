#Problem Link:- https://leetcode.com/problems/distant-barcodes/

"""In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any 
answer, and it is guaranteed an answer exists."""

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        import heapq
        n = len(barcodes)
        d = dict()
        for i in range(n):
            if barcodes[i] not in d:
                d[barcodes[i]] = 1
            else:
                d[barcodes[i]] += 1
        dist = 0
        num = None
        heap = []
        ans = [None] * n
        for x in d:
            heapq.heappush(heap,(-d[x],x))
        for i in range(0,n,2):
            if dist == 0:
                dist,num = heapq.heappop(heap)
                dist = -dist
            ans[i] = num
            dist -= 1
        for i in range(1,n,2):
            if dist == 0:
                dist,num = heapq.heappop(heap)
                dist = -dist
            ans[i] = num
            dist -= 1
        return ans