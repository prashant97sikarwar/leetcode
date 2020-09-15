class Solution(object):
    def countSubstrings(self, s):
        if len(s) <= 1:
            return 1
        count = [0]
        for i in range(len(s)):
            self.helper(s,i,i,count)
            self.helper(s,i,i+1,count)
        return count[0] 
                
    def helper(self,s,i,j,count):
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
            count[0] += 1
        