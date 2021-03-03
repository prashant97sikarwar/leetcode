//Problem Link:- https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/

/* You are given two strings, word1 and word2. You want to construct a string in the following 
manner:
1.Choose some non-empty subsequence subsequence1 from word1.
2.Choose some non-empty subsequence subsequence2 from word2.
3.Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
Return the length of the longest palindrome that can be constructed in the described manner. If no 
palindromes can be constructed, return 0. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>> & dp, string s){
        int j;
        for(int l=2;l<=s.length();l++){
            for(int i=0;i<s.length()-l+1;i++){
                j = i+l-1;
                dp[i][j] = (s[i] == s[j]) ? (dp[i+1][j-1] + ((l == 1) ? 1 : 2)) : max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.length()-1];
    }
    
    int longestPalindrome(string word1, string word2) {
        int sz = word1.length() + word2.length();
        vector<vector<int>> dp(sz+1,vector<int>(sz+1));
        helper(dp, word1+word2);
        int res = 0;
        for(int i=0;i<word1.length();i++){
            for(int j=word2.length()-1;j>=0;j--){
                if (word1[i] == word2[j]){
                    res = max(res,dp[i][word1.length()+j+1]);
                    break;
                }
            }
        }
        return res;
    }
};