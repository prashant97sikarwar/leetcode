#Problem Link:- https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/

"""You are given a (0-indexed) array of positive integers candiesCount where candiesCount[i] 
represents the number of candies of the ith type you have. You are also given a 2D array queries 
where queries[i] = [favoriteTypei, favoriteDayi, dailyCapi].
You play a game with the following rules:
1.You start eating candies on day 0.
2.You cannot eat any candy of type i unless you have eaten all candies of type i - 1.
3.You must eat at least one candy per day until you have eaten all the candies.
Construct a boolean array answer such that answer.length == queries.length and answer[i] is true 
if you can eat a candy of type favoriteTypei on day favoriteDayi without eating more than dailyCapi 
candies on any day, and false otherwise. Note that you can eat different types of candy on the same 
day, provided that you follow rule 2.Return the constructed array answer."""

class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        for i in range(1,len(candiesCount)):
            candiesCount[i] += candiesCount[i-1]
        ans = []
        for typ,day,cap in queries:
            if typ == 0:
                first = 0
                last = candiesCount[0] - 1
            else:
                first = candiesCount[typ-1] // cap
                last = candiesCount[typ] - 1
            if day >= first and day <= last:
                ans.append(True)
            else:
                ans.append(False)
        return ans