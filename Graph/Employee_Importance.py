#Problem Link:- https://leetcode.com/problems/employee-importance/

"""You are given a data structure of employee information, which includes the employee's 
unique id, their importance value and their direct subordinates' id.Now given the employee 
information of a company, and an employee id, you need to return the total importance value 
of this employee and all their subordinates."""


# Definition for Employee.
class Employee:
    def __init__(self, id,importance, subordinates):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees,id):
        for x in employees:
            if x.id == id:
                src = x
        ans = src.importance
        for dep in src.subordinates:
            ans += self.getImportance(employees,dep)
        return ans
            
                