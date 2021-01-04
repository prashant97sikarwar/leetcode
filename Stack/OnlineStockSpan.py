#Problem Link;- https://leetcode.com/problems/online-stock-span/

"""Write a class StockSpanner which collects daily price quotes for some stock, and returns 
the span of that stock's price for the current day.The span of the stock's price today is 
defined as the maximum number of consecutive days (starting from today and going backwards) 
for which the price of the stock was less than or equal to today's price."""

class StockSpanner(object):

    def __init__(self):
        self.st = []
        
    def next(self, price):
        check = 1
        while self.st and self.st[-1][0] <= price:
            stock,cost = self.st.pop()
            check += cost
        self.st.append((price,check))
        return check        

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)