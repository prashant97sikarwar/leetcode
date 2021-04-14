//Problem Link:- https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = new ListNode();
        ListNode* curr = head;
        ListNode* prev = start;
        start->next = head;
        
        while (curr){
            if (curr->next && curr->val > curr->next->val){
                while(prev->next && (prev->next->val < curr->next->val)){
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = start;
            }
            else{
                curr = curr->next;
            }
        }
        return start->next;
    }
};