//Problem Link:- https://leetcode.com/problems/decode-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string fact;
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='[' || (s[i]>='a' && s[i]<='z')){
                string temp(1,s[i]);
                st.push(temp);
            }
            else if(s[i]>='0' && s[i]<='9'){
                
                string number;
                
                while(s[i]>='0' && s[i]<='9'){
                    number.push_back(s[i]);
                    ++i;
                }
                --i;
                st.push(number);
            }
            else if(s[i]==']'){
        
                fact="";
                while(st.top()!="["){
                    fact=st.top()+fact;
                    st.pop();
                }
                st.pop();
                
                int actual_number = stoi(st.top());

                st.pop();               
                
                string add;
                for(int j=0;j<actual_number;j++)
                    add+=fact;
                
                st.push(add);
            }
        }
        string res="";
        while (!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};