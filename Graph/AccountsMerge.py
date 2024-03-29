#Problem Link:- https://leetcode.com/problems/accounts-merge/

"""Given a list accounts, each element accounts[i] is a list of strings, where the first 
element accounts[i][0] is a name, and the rest of the elements are emails representing 
emails of the account.Now, we would like to merge these accounts. Two accounts definitely 
belong to the same person if there is some email that is common to both accounts. Note 
that even if two accounts have the same name, they may belong to different people as 
people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.After merging the accounts, 
return the accounts in the following format: the first element of each account is the 
name, and the rest of the elements are emails in sorted order. The accounts themselves 
can be returned in any order."""

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        em_to_name = {}
        graph = collections.defaultdict(set)
        for acc in accounts:
            name = acc[0]
            for email in acc[1:]:
                graph[acc[1]].add(email)
                graph[email].add(acc[1])
                em_to_name[email] = name

        seen = set()
        ans = []
        for email in graph:
            if email not in seen:
                seen.add(email)
                stack = [email]
                component = []
                while stack:
                    node = stack.pop()
                    component.append(node)
                    for nei in graph[node]:
                        if nei not in seen:
                            seen.add(nei)
                            stack.append(nei)
                ans.append([em_to_name[email]] + sorted(component))
        return ans