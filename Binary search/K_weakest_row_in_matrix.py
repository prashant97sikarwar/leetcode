class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        l = []
        ans = []
        for i,num in enumerate(mat):
            l.append((sum(num),i))
        l.sort()
        for i in range(k):
            ans.append(l[i][1])
        return ans
        