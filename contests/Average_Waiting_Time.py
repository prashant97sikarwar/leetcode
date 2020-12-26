#Problem Link:- https://leetcode.com/contest/biweekly-contest-42/problems/average-waiting-time/

"""There is a restaurant with a single chef. You are given an array customers, where 
customers[i] = [arrivali, timei]:arrivali is the arrival time of the ith customer. The 
arrival times are sorted in non-decreasing order.timei is the time needed to prepare the
order of the ith customer.When a customer arrives, he gives the chef his order, and the 
chef starts preparing it once he is idle. The customer waits till the chef finishes 
preparing his order. The chef does not prepare food for more than one customer at a 
time. The chef prepares food for customers in the order they were given in the input.
Return the average waiting time of all customers."""

class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        cur_time = customers[0][0] + customers[0][1]
        total = customers[0][1]
        for i in range(1,len(customers)):
            if cur_time > customers[i][0]:
                wait = cur_time - customers[i][0]
                total += wait
            total += customers[i][1]
            cur_time = max(cur_time,customers[i][0]) + customers[i][1]
            
        return total / len(customers)