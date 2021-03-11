# Problem link:- https://leetcode.com/problems/combinations/

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        if n == 1 and k == 1:
            return [[1]]
        arr = [x for x in range(1,n+1)]
        self.helper(n,k,arr,0,0,result,[])
        return result
    
    def helper(self,n,k,arr,index,cnt,result,path):
        if cnt == k:
            result.append(path)
            return 
        if index >= len(arr):
            return 
        self.helper(n,k,arr,index+1,cnt,result,path)
        self.helper(n,k,arr,index+1,cnt+1,result,path+[arr[index]])