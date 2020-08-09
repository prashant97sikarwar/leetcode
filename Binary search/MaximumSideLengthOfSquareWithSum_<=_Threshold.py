class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        col = len(mat[0])
        row = len(mat)
        pf = [[0 for i in range(col+1)] for j in range(row+1)]
        for i in range(row):
            for j in range(col):
                pf[i+1][j+1] = pf[i][j+1] + pf[i+1][j] - pf[i][j] + mat[i][j]
        max_side = 0
        for i in range(row):
            for j in range(col): 

                if min(i, j) >= max_side:
                    curr = pf[i + 1][j + 1]
                    top = pf[i - max_side][j + 1]
                    left = pf[i + 1][j - max_side]
                    topLeft = pf[i - max_side][j - max_side]
                    total = curr - top - left + topLeft
                    if total <= threshold:
                        max_side += 1
        return max_side