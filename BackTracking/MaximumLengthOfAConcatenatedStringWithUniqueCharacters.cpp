//Problem Link:- https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<bool,int> valid(vector<string> temp){
        if (temp.size() == 0){
            return {true,0};
        }
        set<char> st;
        int cnt = 0;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                cnt++;
                if (st.find(temp[i][j]) == st.end()){
                    st.insert(temp[i][j]);
                }
                else{
                    return {false,0};
                }
            }
        }
        return {true,cnt};
    }
    
    int helper(vector<string>& arr,int idx,vector<string> temp){
        auto x = valid(temp);
        if (x.first == false){
            return 0;
        }
        if (idx == arr.size()){
            return x.second;
        }
        temp.push_back(arr[idx]);
        int first = helper(arr,idx+1,temp);
        temp.pop_back();
        int sec = helper(arr,idx+1,temp);
        return max(first,sec);
        
        
    }
    
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0){
            return 0;
        }
        vector<string> temp;
        return helper(arr,0,temp);
        
    }
};