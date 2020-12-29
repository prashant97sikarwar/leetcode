#Problem Link:- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

"""There are several cards arranged in a row, and each card has an associated number of 
points The points are given in the integer array cardPoints.In one step, you can take one 
card from the beginning or from the end of the row. You have to take exactly k cards.Your 
score is the sum of the points of the cards you have taken.Given the integer array cardPoints 
and the integer k, return the maximum score you can obtain."""

class Solution(object):
    def maxScore(self, cardPoints, k):
        sm = 0
        n = len(cardPoints)
        for i in range(n):
            sm += cardPoints[i]
        res = 0
        left = 0
        mnsm = 0
        for i in range(n-k):
            mnsm += cardPoints[i]
        res = max(res,mnsm)
        for i in range(n-k,n):
            mnsm +=  cardPoints[i]
            while (left < n and i-left+1 >  n-k):
                mnsm -= cardPoints[left]
                left+=1
            res = min(res,mnsm)
        return sm-res