//Problem Link:- https://leetcode.com/problems/text-justification/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string leftJustify(vector<string> & words,int diff, int i,int j){
        int spaceOnRight = diff - (j -i -1);
        string result = words[i];
        for(int k=i+1;k<j;++k){
            result += ' '; 
            result += words[k];
        }
        for(int k=0;k<spaceOnRight;++k){
            result += ' '; 
        }
        return result;
    }
    
    string middleJustify(vector<string>& words,int diff, int i,int j){
        int spaceNeeded = j-i-1;
        int spaces = diff / spaceNeeded;
        int extraSpaces = diff % spaceNeeded;
        
        string result = words[i];
        for(int k=i+1;k<j;k++){
            int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
            for(int x=0;x<spacesToApply;++x){
                result += ' ';    
            }
            result += words[k];
        }
        return result;
    }
        
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0,n = words.size();
        while(i < n){
            int j = i+1;
            int lineLength = words[i].length();
            while(j < n && (lineLength+words[j].length() + (j-i-1)) < maxWidth){
                lineLength += words[j].length();
                ++j;
            }
            int diff = maxWidth - lineLength;
            int numberofWords = j-i;
            if (numberofWords == 1 || j >= n){
                result.push_back(leftJustify(words,diff,i,j));
            }
            else{
                result.push_back(middleJustify(words,diff,i,j));
            }
            i = j;
        }
        return result;
    }
};