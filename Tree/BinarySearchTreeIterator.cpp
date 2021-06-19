//Problem Link:- https://leetcode.com/problems/binary-search-tree-iterator/

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

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while (root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        int res = st.top()->val;
        TreeNode* temp = st.top();
        st.pop();
        if (temp->right != NULL){
            temp = temp->right;
            while (temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return (st.empty() ? false : true);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */