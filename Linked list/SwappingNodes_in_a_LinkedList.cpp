//Problem Link:- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL){
            return head;
        }
        if (head->next == NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;
        while (cnt != k && fast != NULL){
            fast = fast->next;
            cnt++;
        }
        while (fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        cnt = 1;
        fast = head;
        while (cnt != k && fast != NULL){
            fast = fast->next;
            cnt++;
        }
        int temp = fast->val;
        fast->val = slow->val;
        slow->val = temp;
        return head;
    }
};