//Problem Link:- https://leetcode.com/problems/merge-k-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        int n = lists.size();
        ListNode* curr;
        for(int i=0;i<n;i++){
            curr = lists[i];
            if (curr != NULL){
                pq.push({curr->val,curr});
            }
        }
        ListNode* result = new ListNode(-1);
        ListNode* ans =  result;
        while (!pq.empty()){
            int data = pq.top().first;
            ListNode* node = pq.top().second;
            result->next = new ListNode(data);
            pq.pop();
            result = result->next;
            if (node->next != NULL){
                pq.push({node->next->val,node->next});
            }
        }
        return ans->next;
    }
};