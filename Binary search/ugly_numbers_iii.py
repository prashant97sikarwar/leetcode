class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        l  = 1
        r = 2000000000+1
        while l < r:
            mid = l + (r-l)//2
            flag = (mid//a) + (mid//b) + (mid//c) -  (mid//(self.lcm(a,b))) - (mid//self.lcm(b,c)) - (mid//self.lcm(a,c)) + (mid//self.lcm(a,self.lcm(b,c)))
            if flag < n:
                l = mid+1
            else:
                r = mid
        return l
                
    
    def gcd(self,a,b):
        if a == 0:
            return b
        else:
            return self.gcd(b%a,a)
    
    def lcm(self,a,b):
        if a == 0 or b == 0:
            return 0
        else:
            return (a*b//self.gcd(a,b))