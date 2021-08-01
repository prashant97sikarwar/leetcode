//Problem Link:- https://leetcode.com/problems/basic-calculator-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prec(char ch){
        if (ch == '/' || ch == '*'){
            return 2;
        }
        else if (ch == '+' || ch == '-'){
            return 1;
        }
        return -1;
    }
    
    int evalPostfix(vector<string>& tokens) {
        const int n = tokens.size();
        stack<int> st;
        int op1, op2;
        for(string& s : tokens){
            if (s.length() == 1 && (s[0] == '-' || s[0] == '+' || s[0] == '/' || s[0] == '*')){
                op1 = st.top();
                st.pop();
                op2 = st.top();
                st.pop();
                if (s[0] == '-'){
                    st.push(op2 - op1);
                }
                else if (s[0] == '/'){
                    st.push(op2/op1);
                }
                else if (s[0] == '+'){
                    st.push(op1 + op2);
                }
                else{
                    st.push(op2*op1);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
    
    vector<string> postFix(string& s,int n){
        vector<string> result;
        stack<char> st;
        string num;
        for(int i=0;i<n;i++){
            if (s[i] == ' '){
                continue;
            }
            else if (s[i] >= '0' && s[i] <= '9'){
                num.push_back(s[i]);
            }
            else{
                result.push_back(num);
                num.clear();
                while (!st.empty() && prec(st.top()) >= prec(s[i])){
                    char ch = st.top();
                    if (ch == '+'){
                        result.push_back("+");
                    }
                    else if (ch == '-'){
                        result.push_back("-");
                    }
                    else if (ch == '/'){
                        result.push_back("/");
                    }
                    else if (ch == '*'){
                        result.push_back("*");
                    }
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        result.push_back(num);
        while (!st.empty()){
            char ch = st.top();
            if (ch == '+'){
                result.push_back("+");
            }
            else if (ch == '-'){
                result.push_back("-");
            }
            else if (ch == '/'){
                result.push_back("/");
            }
            else if (ch == '*'){
                result.push_back("*");
            }
            st.pop();
        }
        return result;
    }
    
    int calculate(string s) {
        const int n = s.length();
        vector<string> postStr = postFix(s,n);
        int result = evalPostfix(postStr);
        return result;
    }
};