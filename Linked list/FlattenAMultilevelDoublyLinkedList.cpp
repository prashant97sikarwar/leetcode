//Problem Link:- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head){
            return NULL;
        }
        Node* cur = head;
        stack<Node*> st;
        while (cur){
            if (cur->child){
                if (cur->next){
                    st.push(cur->next);
                }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
            }
            else if (cur->next == NULL && !st.empty()){
                cur->next = st.top();
                cur->next->prev = cur;
                st.pop();
            }
            cur = cur->next;
        }
        return head;
    }
};