"""Given two strings S and T, return if they are equal when both 
are typed into empty text editors. # means a backspace character.
Note that after backspacing an empty text, the text will continue empty."""

class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        st1 = []
        st2 = []
        for i in S:
            if i == '#' and st1:
                st1.pop()
            if i != '#':
                st1.append(i)
        for j in T:
            if j == '#' and st2:
                st2.pop()
            if j != '#':
                st2.append(j)

        if st1 == st2:
            return True
        return False