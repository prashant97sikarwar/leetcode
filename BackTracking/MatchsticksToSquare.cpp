//Problem Link:- https://leetcode.com/problems/matchsticks-to-square/

/*please find out a way you can make one square by using up all those matchsticks. You should 
not break any stick, but you can link them up, and each matchstick must be used exactly one 
time.Your input will be several matchsticks,represented with their stick length. Your output 
will either be true or false, to represent whether you could make one square using all the 
matchsticks. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool helper(vector<int>& nums,int index, int s1, int s2, int s3, int s4, int pos){
        if (index == nums.size())
            return (s1 == pos && s2 == pos && s3 == pos && s4 == pos);
        if ((nums[index] + s1 <= pos) && helper(nums,index+1,s1+nums[index],s2,s3,s4,pos)){
            return true;
        }
        if ((nums[index] + s2 <= pos) && helper(nums,index+1,s1,s2+nums[index],s3,s4,pos)){
            return true;
        }
        if ((nums[index] + s3 <= pos) && helper(nums,index+1,s1,s2,s3+nums[index],s4,pos)){
            return true;
        }
        if ((nums[index] + s4 <= pos) && helper(nums,index+1,s1,s2,s3,s4+nums[index],pos)){
            return true;
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int sm = accumulate(nums.begin(),nums.end(),0);
        if (sm % 4 != 0)
            return false;
        int pos = sm / 4;
        if (n < 4 )
            return false;
        sort(nums.rbegin(),nums.rend());
        return helper(nums,0,0,0,0,0,pos);
    }
};