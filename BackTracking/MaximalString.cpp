//Problem Link:- https://www.interviewbit.com/problems/maximal-string/

#include<bits/stdc++.h>
using namespace std;

string mx="";
void find(string a,int k){
    if(k==0){
        if(mx<a) mx=a;
        return;
    }
    for(int i=0;i<a.length();i++){
        for(int j=i+1;j<a.length();j++){
            swap(a[i],a[j]);
            find(a,k-1);
            swap(a[i],a[j]);
        }
    }
}
string solve(string A, int B) {
    mx="";
    find(A,B);
    return mx;
}