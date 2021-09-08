//Problem Link:- https://leetcode.com/problems/gcd-sort-of-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    const int MAX = 100007;
    int parent[100007];
    int rank[100007];
public:
    vector<int> spf; 
    int find(int u){
        if (u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        int x = find(u);
        int y = find(v);
        
        if (x == y){
            return;
        }
        if (rank[x] > rank[y]){
            parent[y] = x;
            rank[x] += rank[y];
        }
        else{
            rank[y] += rank[x];
            parent[x] = y;
        }
    }
    
    int gcd(int a, int b){
        if (b == 0){
            return a;
        }
        return gcd(b,a%b);
    }
    
    void sieve(int n){
        spf.resize(n);
        
        for(int i=2;i<n;i++){
            spf[i] = i;
        }
        for(int i=2;i*i<n;i++){
            if (spf[i] == i){
                for(int j=i*i;j<n;j+=i){
                    if (spf[j] > i){
                        spf[j] = i;
                    }
                }
            }
            
        }
    }
    vector<int> helper(int n) { // O(logN)
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
   
    bool gcdSort(vector<int>& nums) {
        const int n = nums.size();
        
        for(int i=0;i<MAX;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        int mx = *max_element(nums.begin(),nums.end());
        
        sieve(mx+1);
        for(int x : nums){
            vector<int> factors = helper(x);
            for(int y : factors){
                merge(x,y);
            }
        }
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if (arr[i] != nums[i]){
                int x = find(nums[i]);
                int y = find(arr[i]);
                
                if (x != y){
                    return false;
                }
            }
        }
        return true;
    }
};