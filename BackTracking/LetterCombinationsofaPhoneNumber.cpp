//Problem Link:- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string digits, vector<string> &result, vector<string> strings, string curr,int index){
        if (index >= digits.length()){
            result.push_back(curr);
            return ;
        }
        string letter = strings[digits[index]-'0'];
        for(int i=0;i<letter.length();i++){
            helper(digits,result,strings,curr+letter[i], index+1);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0)
            return result;
        vector<string> strings = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,result,strings,"",0);
        return result;
    }
};