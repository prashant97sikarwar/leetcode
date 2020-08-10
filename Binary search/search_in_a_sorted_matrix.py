class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        n = len(matrix[0])
        for i in range(len(matrix)):
            if matrix[i][n-1] == target:
                return True
            elif matrix[i][n-1] > target:
                return self.search(target,0,n-1,matrix[i])
            else:
                continue
        return False
        
        
        
    def search(self,target,l,r,arr):
        while l <= r:
            mid = l + (r-l)//2
            if arr[mid] == target:
                return True
            elif arr[mid] > target:
                r = mid-1
            else:
                l = mid + 1
        return False