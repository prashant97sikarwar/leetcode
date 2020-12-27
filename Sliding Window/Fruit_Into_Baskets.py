#Problem Link:- https://leetcode.com/problems/fruit-into-baskets/

"""In a row of trees, the i-th tree produces fruit with type tree[i].You start at any 
tree of your choice, then repeatedly perform the following steps:Add one piece of fruit 
from this tree to your baskets.  If you cannot, stop.Move to the next tree to the right 
of the current tree.  If there is no tree to the right, stop.You have two baskets, and 
each basket can carry any quantity of fruit, but you want each basket to only carry one 
type of fruit each.What is the total amount of fruit you can collect with this procedure?"""

class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        left = 0
        d = dict()
        n = len(tree)
        res = 0
        for i in range(n):
            if tree[i] not in d:
                d[tree[i]] = 1
            else:
                d[tree[i]] += 1
            while(left < n and len(d) > 2):
                d[tree[left]] -= 1
                if d[tree[left]] == 0:
                    d.pop(tree[left])
                left += 1
            res = max(res,i-left+1)
        return res
