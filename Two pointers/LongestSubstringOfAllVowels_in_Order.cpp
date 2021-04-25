//Problem Link:- https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/

/*A string is considered beautiful if it satisfies the following conditions:
1.Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
2.The letters must be sorted in alphabetical order
Given a string word consisting of English vowels, return the length of the longest beautiful 
substring of word. If no such substring exists, return 0.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0;
        int unique = 1;
        int total = 1;
        for(int i=1;i<word.length();i++){
            if (word[i-1] == word[i]){
                total++;
            }
            else if (word[i-1] < word[i]){
                total++;
                unique++;
            }
            else{
                total = 1;
                unique = 1;
            }
            if (unique >= 5){
                ans = max(ans,total);
            }
        }
        return ans;
    }
};