//Problem link:- https://leetcode.com/problems/count-and-say/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans;
        if (n == 1){
            ans = "1";
            return ans;
        }
        if (n == 2){
            ans = "11";
            return ans;
        }
        if (n == 3){
            ans = "21";
            return ans;
        }
        string temp = "21";
        for(int i=4;i<=n;i++){
            string res = "";
            int cnt = 1;
            for(int j=0;j<temp.length()-1;j++){
                if (temp[j] == temp[j+1]){
                    cnt++;
                }
                else{
                    res += to_string(cnt);
                    res += temp[j];
                    cnt = 1;
                }
            }
            res += to_string(cnt);
            res += temp[temp.length()-1];
            temp = res;
        }
        return temp;
    }
};