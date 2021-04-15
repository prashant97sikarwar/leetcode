//Problem Link:- https://leetcode.com/problems/merge-k-sorted-lists/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = lists.size();
        ListNode* curr;
        for(int i=0;i<n;i++){
            curr = lists[i];
            while(curr != NULL){
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        if (pq.size() == 0){
            ListNode* head = NULL;
            return head;
        }
        ListNode* result = new ListNode(-1);
        ListNode* ans = result;
        while(!pq.empty()){
            result->next = new ListNode(pq.top());
            pq.pop();
            result = result->next;
        }
        return ans->next;
    }
};