class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num == 0:
            return False
        if num == 1:
            return True
        dep = 1
        for i in range(2,32,2):
            if num & (dep << i) == num:
                return True
        return False