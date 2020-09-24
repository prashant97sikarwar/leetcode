"""You are given K eggs, and you have access to a building with N floors from 1 to N. 
Each egg is identical in function, and if an egg breaks, you cannot drop it again.
You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a 
floor higher than F will break, and any egg dropped at or below floor F will not break.
Each move, you may take an egg (if you have an unbroken one) and drop it from any floor 
X (with 1 <= X <= N). Your goal is to know with certainty what the value of F is.
What is the minimum number of moves that you need to know with certainty what F is, 
regardless of the initial value of F?"""

#below solution has time complexity O(NlogK)

class Solution(object):
    def superEggDrop(self, K, N):
        low = 1
        high = N
        while(low<high):
            mid = (low+high)//2
            if(self.bCoff(mid,K,N) < N):
                low = mid+1
            else:
                high = mid
        return int(low)

    def bCoff(self,x,k,n):
        sum = 0
        term = 1
        i = 1
        while(i<=k and sum<n):
            term *= x-i+1
            term /= i
            sum+=term
            i+=1
        return sum
    
#below solution has time complexity O(K*N^2)

class Solution(object):
    def superEggDrop(self, K, N):
        floors = N
        eggs = K
        dp = [[0 for i in range(floors+1)] for i in range(eggs+1)]
        for i in range(eggs + 1):
            dp[i][0] = 0
            dp[i][1] = 1
        for i in range(1,floors+1):
            dp[1][i] = i
        for i in range(2,eggs+1):
            for j in range(2,floors+1):
                dp[i][j] = float('inf')
                for k in range(1,j+1):
                    res = 1 + max(dp[i-1][k-1],dp[i][j-k])
                    dp[i][j] = min(dp[i][j], res)
        return dp[eggs][floors]
    
    