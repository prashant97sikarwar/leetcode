#Problem Link:- https://leetcode.com/problems/decode-ways/

"""A message containing letters from A-Z can be encoded into numbers.Given a string s containing
only digits, return the number of ways to decode it.The answer is guaranteed to fit in a 32-bit 
integer. """

class Solution:
    def numDecodings(self, s: str) -> int:
        
        def valid(s):
            if s[0] == '0' or len(s) == 0:
                return False
            return int(s) >= 1 and int(s) <= 26
        
        def helper(s,ptr,dp):
            if ptr == len(s):
                return 1
            if dp[ptr] != -1:
                return dp[ptr]
            
            total = 0
            for i in range(1,3):
                if ptr+i <= len(s):
                    string = s[ptr : ptr + i]
                    if valid(string):
                        total += helper(s,ptr + i,dp)
                        
            dp[ptr] = total
            return dp[ptr]
        
        n = len(s)
        dp = [-1 for i in range(n)]
        return helper(s,0,dp)