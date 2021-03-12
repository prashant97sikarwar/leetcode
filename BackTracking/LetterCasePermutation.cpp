//Problem Link:- https://leetcode.com/problems/letter-case-permutation/

/* Given a string S, we can transform every letter individually to be lowercase or uppercase 
to create another string.Return a list of all possible strings we could create. You can 
return the output in any order. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void helper(vector<string>& result,string curr,string S,int index){
        if (curr.length() == S.length()){
            result.push_back(curr);
            return;
        }
        if (isdigit(S[index])){
            curr.push_back(S[index]);
            helper(result,curr,S,index+1);
            curr.pop_back();
        }
        else if (isalpha(S[index]) && isupper(S[index])){
            char f = tolower(S[index]);
            curr.push_back(f);
            helper(result,curr,S,index+1);
            curr.pop_back();
            curr.push_back(S[index]);
            helper(result,curr,S,index+1);
            curr.pop_back();
                        
        }
        else if (isalpha(S[index]) && islower(S[index])){
            char f = toupper(S[index]);
            curr.push_back(f);
            helper(result,curr,S,index+1);
            curr.pop_back();
            curr.push_back(S[index]);
            helper(result,curr,S,index+1);
            curr.pop_back();
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        string curr;
        helper(result,curr,S,0);
        return result;
    }
};