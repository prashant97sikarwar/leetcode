//Problem Link:- https://leetcode.com/contest/biweekly-contest-43/problems/construct-the-lexicographically-largest-valid-sequence/

/* Given an integer n, find a sequence that satisfies all of the following:
The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is 
exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference 
of their indices, |j - i|.Return the lexicographically largest sequence. It is guaranteed 
that under the given constraints, there is always a solution. */


#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> used;
    bool dfs(vector<int> &ans, int i){
        if( i == ans.size()) return true;
        if (ans[i]) 
            return dfs(ans,i+1);
        for(int j = used.size()-1;j > 0;--j){
            if (used[j]) 
                continue;
            if (j != 1 && (i+j >= ans.size() || ans[i+j]))
                continue;
            used[j] = 1;
            ans[i] = j;
            if (j != 1) ans[i + j] = j;
            if (dfs(ans, i + 1)) 
                return true;
            ans[i] = 0; // this filling is invalid, backtrack and try the next number.
            if (j != 1) 
                ans[i + j] = 0;
            used[j] = 0;
        }
        return false;
    }
    
    
    
public:
    vector<int> constructDistancedSequence(int n) {
        vector <int> ans(2*n-1);
        used.assign(n+1,0);
        dfs(ans,0);
        return ans;
    }
};