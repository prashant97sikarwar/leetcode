#Problem Link:- https://leetcode.com/problems/where-will-the-ball-fall/

"""You have a 2-D grid of size m x n representing a box, and you have n balls. The box is 
open on the top and bottom sides.Each cell in the box has a diagonal board spanning two 
corners of the cell that can redirect a ball to the right or to the left.A board that 
redirects the ball to the right spans the top-left corner to the bottom-right corner and 
is represented in the grid as 1.A board that redirects the ball to the left spans the top-
right corner to the bottom-left corner and is represented in the grid as -1.We drop one 
ball at the top of each column of the box. Each ball can get stuck in the box or fall out 
of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if 
a board redirects the ball into either wall of the box.Return an array answer of size n 
where answer[i] is the column that the ball falls out of at the bottom after dropping the 
ball from the ith column at the top, or -1 if the ball gets stuck in the box."""

class Solution(object):
    def findBall(self, grid):
        n = len(grid)
        m = len(grid[0])
        ans = []
        
        def corner(x):
            return 1 if x == -1 else -1
        
        def helper(n,m,i,j):
            while i < n:
                cur_pos = grid[i][j]
                if cur_pos == 1:
                    neigh = grid[i][j+1] if j+1 < m else corner(cur_pos)
                else:
                    neigh = grid[i][j-1] if j-1 >= 0 else corner(cur_pos)
                if cur_pos + neigh == 0:
                    return -1
                elif cur_pos + neigh == 2:
                    j += 1
                else:
                    j -= 1
                i += 1
            return j
            
            
        for j in range(m):
            ans.append(helper(n,m,0,j))
        return ans
        