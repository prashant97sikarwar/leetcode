//Problem Link:- https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

/* you are given a string time in the form of hh:mm, where some of the digits in the string 
are hidden (represented by ?).The valid times are those inclusively between 00:00 and 23:59.
Return the latest valid time you can get from time by replacing the hidden digits. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        string ans = "";
        if (time[0] == '?' && time[1] == '?'){
            ans += '2';
            ans  += '3';
        }
        else{
            if (time[0] == '?' && time[1] -'0' < 4){
                ans += '2';
            }
            if (time[0] == '?' && time[1] -'0' >= 4)
                ans += '1';
            if (time[0] != '?')
                ans += time[0];
            if (time[1] == '?'){
                if (time[0] == '0' || time[0] == '1' || ans[0] == '1')
                    ans += '9';
                if (time[0] == '2' || ans[0] == '2')
                    ans += '3';
            }
            if (time[1] != '?')
                ans += time[1];
            }

        ans += ':';
        if (time[3] == '?')
            ans += '5';
        if (time[3] != '?')
            ans += time[3];
        if (time[4] == '?')
            ans += '9';
        if (time[4] != '?')
            ans += time[4];
        return ans;
    }
};