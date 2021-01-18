#Problem Link:- https://leetcode.com/problems/knight-probability-in-chessboard/

"""On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make 
exactly K moves.Each time the knight is to move, it chooses one of eight possible moves uniformly
at random (even if the piece would go off the chessboard) and moves there.The knight continues 
moving until it has made exactly K moves or has moved off the chessboard. Return the probability
that the knight remains on the board after it has stopped moving."""

class Solution(object):
    def knightProbability(self, N, K, r, c):
        dp = [[[-1 for i in range(K)] for i in range(N)] for i in range(N)]
        self.K = K
        def helper(x,y,n,k):
            dx = [-2,-1,1,2,2,1,-1,-2]
            dy = [1,2,2,1,-1,-2,-2,-1]
            
            if x < 0 or y < 0 or x > n-1 or y > n-1:
                return 0
            
            if k == self.K:
                return 1
            
            if dp[x][y][k] != -1:
                return dp[x][y][k]
            
            res = 0
            for i in range(8):
                res += helper(x+dx[i],y+dy[i],n,k+1)
            dp[x][y][k] = res
            return res
        
        return helper(r,c,N,0) / float(pow(8,K))
