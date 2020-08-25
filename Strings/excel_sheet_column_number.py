"""Given a column title as appear in an Excel sheet, 
return its corresponding column number."""


class Solution(object):
    def titleToNumber(self, s):
        st = []
        n = len(s)
        for i in range(n):
            st.append(s[i])
        ans = 0
        for i in range(n):
            dep = ord(st.pop()) - ord('A') + 1
            ans += (26**i) * dep
        return ans
            
                        
        