//Problem Link:- https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int helper(TreeNode* root, int mx){
        if (!root){
            return 0;
        }
        if (root->val >= mx){
            mx = root->val;
            return 1 + helper(root->left,mx) + helper(root->right,mx);
        }
        return helper(root->left,mx) + helper(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        if (!root->left && !root->right){
            return 1;
        }
        return 1 + helper(root->left,root->val) + helper(root->right,root->val);
    }
};