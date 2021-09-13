//Problem Link:- https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        const int n = s.length();
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        vector<int> nums;
        for(int i=0;i<26;i++){
            if (freq[i] > 0){
                nums.push_back(freq[i]);
            }
        }
        sort(nums.rbegin(),nums.rend());
        int result = 0;
        int high = nums[0]-1;
        for(int i=1;i<nums.size();i++){
            if (high <= 0){
                result += nums[i];
            }
            else if (high > nums[i]){
                high = nums[i]-1;
            }
            else{
                result += (nums[i] - high);
                nums[i] = high;
                high = nums[i] - 1;
            }
        }
        return result;
    }
};