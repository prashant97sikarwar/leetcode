//Problem Link:- https://leetcode.com/problems/invalid-transactions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& nums) {
        vector<string> name, city,result;
        vector<int> time, amount;
        int n = nums.size();
        for(string& s : nums){
            string str;
            int cnt = 0;
            for(int i=0;i<s.length();i++){
                if (s[i] == ',' || i == s.length()-1){
                    cnt++;
                    if (cnt == 1){
                        name.push_back(str);
                    }
                    else if (cnt == 2){
                        time.push_back(stoi(str));
                    }
                    else if (cnt == 3){
                        amount.push_back(stoi(str));
                    }
                    else if(i == s.length()-1){
                        str.push_back(s[i]);
                        city.push_back(str);
                    }
                    str.clear();
                }
                else{
                    str.push_back(s[i]);
                }
            }
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if (amount[i] > 1000){
                st.insert(i);
            }
            for(int j=i+1;j<n;j++){
                if (name[i] == name[j] && city[i] != city[j] && abs(time[i]-time[j]) <= 60){
                    st.insert(i);
                    st.insert(j);  
                }
            }
        }
        for(auto it=st.begin();it!=st.end();it++){
            result.push_back(nums[*it]);
        }
        return result;   
    }
};