"""Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
"""


class Solution:
    def isValid(self, s):
        stack = []
        for char in s:
            if char in ['(' , '[' , '{']:
                stack.append(char)
            else:
                if not stack:
                    return False
                current_char = stack.pop() 
                if current_char == '(': 
                    if char != ")": 
                        return False
                if current_char == '{': 
                    if char != "}": 
                        return False
                if current_char == '[': 
                    if char != "]": 
                        return False
        # If stack is empty
        if stack: 
            return False
        return True