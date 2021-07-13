//Problem Link:- https://leetcode.com/problems/frog-jump/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int> mp;
    
    int dp[2005][2005];
    vector<int> v;
    
    int ans(int pos,int lst)
    {
        
        if(pos==v.size()-1)
        {
            return 1;
        }
        if(dp[pos][lst]!=-1)
        {
            return dp[pos][lst];
        }
        
        int an=0;
        if((mp.find(v[pos]+lst)!=mp.end())&&(lst!=0))
        {
            an=max(an,ans(mp[v[pos]+lst],lst));
        }
        if((mp.find(v[pos]+lst-1)!=mp.end())&&(lst-1 !=0))
        {
            an=max(an,ans(mp[v[pos]+lst-1],lst-1));
        }
        if(mp.find(v[pos]+lst+1)!=mp.end())
        {
            an=max(an,ans(mp[v[pos]+lst+1],lst+1));
        }
        return (dp[pos][lst]=an);
    }
    
    bool canCross(vector<int>& stones) {
        v=stones;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        if(v[1]!=1)
        {
            return false;
        }
        return ans(1,1);
    }
};