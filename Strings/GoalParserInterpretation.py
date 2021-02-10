#Problem Link:- https://leetcode.com/contest/weekly-contest-218/problems/goal-parser-interpretation/

"""You own a Goal Parser that can interpret a string command. The command consists of an alphabet
of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", 
"()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated 
in the original order.Given the string command, return the Goal Parser's interpretation of 
command."""

class Solution(object):
    def interpret(self, command):
        i = 0
        ans = ""
        n = len(command)
        while i < n:
            if command[i] == 'G':
                ans += "G"
                i += 1
            elif command[i] == "(":
                if i+1 < n and command[i+1] == ')':
                    ans += "o"
                    i += 2
                elif i+1 < n and command[i+1] != ')':
                    ans += "al"
                    i += 4
        return ans