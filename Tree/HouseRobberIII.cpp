//Problem Link:- https://leetcode.com/problems/house-robber-iii/

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
    pair<int,int> helper(TreeNode* root){
        if (!root){
            return {0,0};
        }
        pair<int,int> leftans = helper(root->left);
        pair<int,int>rightans = helper(root->right);
        int rob = root->val + leftans.second + rightans.second;
        int not_rob = max(leftans.first,leftans.second) + max(rightans.first,rightans.second);
        return {rob,not_rob};
    }
    
    int rob(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        if (!root->left && !root->right){
            return root->val;
        }
        pair<int,int> result = helper(root);
        return max(result.first,result.second);
    }
};