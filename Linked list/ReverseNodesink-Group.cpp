//Problem Link:- https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1){
            return head;
        }
        deque<ListNode*> pq;
        int cnt = 0;
        ListNode* curr = head;
        ListNode* start = new ListNode(-1);
        ListNode* dummy = start;
        while (curr != NULL){
            for(int i=0;i<k;i++){
                pq.push_back(curr);
                curr = curr->next;
                if (curr == NULL){
                    break;
                }
            }
            if (pq.size() == k){
                while (!pq.empty()){
                    start->next = pq.back();
                    start = start->next;
                    pq.pop_back();
                }
            }
            else{
                while (!pq.empty()){
                    start->next = pq.front();
                    start = start->next;
                    pq.pop_front();
                }
            }
        }
        start->next = NULL;
        return dummy->next;
    }
};