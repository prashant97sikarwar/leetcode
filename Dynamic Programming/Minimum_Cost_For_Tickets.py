"""In a country popular for train travel, you have planned some train travelling 
one year in advance.  The days of the year that you will travel is given as an array 
days.  Each day is an integer from 1 to 365.Train tickets are sold in 3 different ways:
a 1-day pass is sold for costs[0] dollars;a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.The passes allow that many days of consecutive 
travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 
day 2, 3, 4, 5, 6, 7, and 8.Return the minimum number of dollars you need to travel 
every day in the given list of days."""


class Solution(object):
    def mincostTickets(self, days, costs):
        n = days[len(days)-1]
        dp = [0 for i in range(n+1)]
        j = 0 
        for i in range(1,n+1):
            if i == days[j]:
                j += 1
                dp[i] = min(dp[max(0,i-1)] + costs[0], dp[max(0,i-7)] + costs[1], dp[max(0,i-30)] + costs[2])
            else:
                dp[i] = dp[i-1]
        return dp[n]
                