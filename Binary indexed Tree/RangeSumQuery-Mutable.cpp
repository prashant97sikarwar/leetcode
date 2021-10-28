//Problem Link:- https://leetcode.com/problems/range-sum-query-mutable/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
    private:
    int N = 30009;
    int bit[30009];
    int nums[30009];
    int n;
public:
    void helper(int i, int x){
        for(;i<N;i += (i&-i)){
            bit[i] += x;
        }
    }
    NumArray(vector<int>& arr) {
        n = arr.size();
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++){
            nums[i+1] = arr[i];
            helper(i+1, arr[i]);
        }
    }
    
    
    void update(int index, int val) {
        helper(index+1, val - nums[index+1]);
        nums[index+1] = val;
        
    }
    
    int sum(int i){
        int res = 0;
        for(;i>0;i -= (i&-i)){
            res += bit[i];
        }
        return res;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */