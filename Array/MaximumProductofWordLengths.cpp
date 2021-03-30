//Problem Link:- https://leetcode.com/problems/maximum-product-of-word-lengths/

/* Given a string array words, return the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. If no such two words exist, return 0.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for(int i=0;i<n;i++){
            vector<int> freq1(26,0);
            for(int w=0;w<words[i].length();w++){
                freq1[words[i][w]-'a']++;
            }
            for(int j=i+1;j<n;j++){
                vector<int> freq2(26,0);
                for(int w=0;w<words[j].length();w++){
                    freq2[words[j][w]-'a']++;
                }
                bool flag = false;
                for(int c=0;c<26;c++){
                    if (freq1[c] > 0 && freq2[c] > 0){
                        flag = true;
                        break;
                    }
                }
                if (flag == false){
                    int ln = words[i].length() * words[j].length();
                    res = max(res,ln);
                }
            }
        }
        return res;
    }
};