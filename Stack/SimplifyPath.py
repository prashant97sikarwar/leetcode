# Problem Link:- https://leetcode.com/problems/simplify-path/

class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        n = len(path)
        i = 0
        temp = ""
        while i < n:
            if (path[i] != "/"):
                temp += path[i]
                i += 1
            elif (path[i] == "/" and temp == ".." and len(st) > 0):
                st.pop()
                i += 1
                temp = ""
            elif (path[i] == "/" and temp == "."):
                i += 1
                temp = ""
            elif (path[i] == "/" and len(temp) > 0 and temp != ".." and temp != "."):
                st.append(temp)
                i += 1
                temp = ""
            else:
                i += 1
                temp = ""
        if (len(temp) > 0 and temp != "." and temp != ".."):
            st.append(temp)
        if (temp == ".." and len(st) > 0):
            st.pop()
        res = ""
        for i in range(len(st)):
            res += "/"
            res += st[i]
        return res if len(res) > 0 else "/"
            