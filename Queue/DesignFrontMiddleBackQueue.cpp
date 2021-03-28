//Problem Link:- https://leetcode.com/problems/design-front-middle-back-queue/

#include<bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    int n1,n2;
    FrontMiddleBackQueue() {
        n1 = 0;
        n2 = 0;
    }
    
    void pushFront(int val) {
        left.push_front(val);
        if (n1 == n2)
            n1++;
        else{
            right.push_front(left.back());
            left.pop_back();
            n2++;
        }
    }
    
    void pushMiddle(int val) {
        if (n1 == n2){
            left.push_back(val);
            n1++;
        }
        else{
            right.push_front(left.back());
            left.pop_back();
            left.push_back(val);
            n2++;
        }
    }
    
    void pushBack(int val) {
        right.push_back(val);
        if (n2 < n1){
            n2++;   
        }
        else{
            left.push_back(right.front());
            right.pop_front();
            n1++;
        }
    }
    
    int popFront() {
        if (n1 == 0 && n2 == 0){
            return -1;
        }
        int ans = left.front();
        left.pop_front();
        n1--;
        if (n1 < n2){
            left.push_back(right.front());
            right.pop_front();
            n2--;
            n1++;
        }
        return ans;
    }
    
    int popMiddle() {
        if (n1 == 0 && n2 == 0) return -1;
        int ans = left.back();
        left.pop_back();
        n1--;
        if (n1 < n2){
            left.push_back(right.front());
            right.pop_front();
            n1++;
            n2--;
        }
        return ans;
    }
    
    int popBack() {
        if (n1 == 0 && n2 == 0)
            return -1;
        if (n2 == 0){
            int ans = left.back();
            left.pop_back();
            n1--;
            return ans;
        }
        int ans = right.back();
        right.pop_back();
        n2--;
        if (n2+1 < n1){
            right.push_front(left.back());
            left.pop_back();
            n2++;
            n1--;
        }
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */