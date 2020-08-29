"""Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it."""


class Solution(object):
    def generate(self, numRows):
        ans = []
        for i in range(1,numRows+1):
            flag = [1]*i
            for j in range(1,i-1):
                flag[j] = ans[-1][j-1] + ans[-1][j]
            ans.append(flag)
        return ans
            