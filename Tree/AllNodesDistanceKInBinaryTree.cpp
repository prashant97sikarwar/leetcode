//Problem Link:- https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
    void dfs(TreeNode* root,TreeNode* par,unordered_map<TreeNode*,TreeNode*>& parent){
        if (!root){
            return;
        }
        parent[root] = par;
        dfs(root->left,root,parent);
        dfs(root->right,root,parent);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        dfs(root,NULL,parent);
        vector<int> result;
        queue<pair<TreeNode*,int>> pq;
        pq.push({target,0});
        unordered_set<TreeNode*> seen;
        seen.insert(target);
        while (!pq.empty()){
            auto x = pq.front();
            if (x.second == k){
                break;
            }
            pq.pop();
            TreeNode* node = x.first;
            int d = x.second;
            if (node->left && seen.count(node->left) == 0){
                pq.push({node->left,d+1});
                seen.insert(node->left);
            }
            if (node->right && seen.count(node->right) == 0){
                pq.push({node->right,d+1});
                seen.insert(node->right);
            }
            if (parent[node] != NULL && seen.count(parent[node]) == 0){
                pq.push({parent[node],d+1});
                seen.insert(parent[node]);
            }
        }
        while (!pq.empty()){
            pair<TreeNode*,int> pr = pq.front();
            pq.pop();
            result.push_back(pr.first->val);
        }
        return result;
    }
};