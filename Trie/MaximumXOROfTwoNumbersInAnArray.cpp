//Problem Link:- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    class TrieNode{
        public:
        TrieNode* left;
        TrieNode* right;

    };
public:
    void insert(int n, TrieNode* root){
        TrieNode* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (1 << i) & n;
            if (bit == 0){
                if (!cur->left){
                    cur->left = new TrieNode();
                }
                cur = cur->left;
            }
            else{
                if (!cur->right){
                    cur->right = new TrieNode();
                }
                cur = cur->right;
            }
        }
    }
    int findres(TrieNode* root, vector<int> &nums){
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            TrieNode* cur = root;
            int val = nums[i];
            int cur_mx = 0;
            for(int j=31;j>=0;j--){
                int bit = (1 << j) & val;
                if (bit == 0){
                    if (cur->right){
                        cur = cur->right;
                        cur_mx += pow(2,j);
                    }
                    else{
                        cur = cur->left;
                    }
                }
                else{
                    if (cur->left){
                        cur_mx += pow(2,j);
                        cur = cur->left;
                    }
                    else{
                        cur = cur->right;
                    }
                }
            }
            res = max(res,cur_mx);
        }
        return res;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            insert(nums[i],root);
        }
        return findres(root,nums);
    }
};