//Problem Link:- https://leetcode.com/problems/maximum-number-of-removable-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s,string p,vector<int> &removable,int guessk){
        
        int i=0;
        int j=0;
        
        vector<bool> hash(s.size(),true);
        
        for(int i=0;i<guessk;i++){
            hash[removable[i]]=false;
        }
        while(i<s.size() and j<p.size()){
            
            
            if(p[j]==s[i] and hash[i]==true){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0;
        int r = removable.size();
        int ans = -1;
        while (l <= r){
            int mid = l + (r-l) / 2;
            if (check(s,p,removable,mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};