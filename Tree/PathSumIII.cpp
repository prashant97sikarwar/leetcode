//Problem Link:- https://leetcode.com/problems/path-sum-iii/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = 0;
    void helper(TreeNode* root,int sm,unordered_map<int,int>&mp,int target){
        if (!root){
            return;
        }
        sm = sm + root->val;
        if (mp.find(sm-target) != mp.end()){
            res += mp[sm-target];
            mp[sm]++;
        }
        else{
            mp[sm]++;
        }
        helper(root->left,sm,mp,target);
        helper(root->right,sm,mp,target);
        mp[sm]--;
        if (mp[sm] == 0){
            mp.erase(sm);
        }
    }
    
    int pathSum(TreeNode* root, int target) {
        if (!root){
            return 0;
        }
        if (!root->left && !root->right && root->val == target){
            return 1;
        }
        unordered_map<int,int> mp;
        mp[0] =  1;
        helper(root,0,mp,target);
        return res;
    }
};