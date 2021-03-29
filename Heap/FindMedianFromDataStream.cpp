//Problem Link:- https://leetcode.com/problems/find-median-from-data-stream/

/* Implement the MedianFinder class:
1.MedianFinder() initializes the MedianFinder object.
2.void addNum(int num) adds the integer num from the data stream to the data structure.
3.double findMedian() returns the median of all elements so far. Answers within 10-5 of 
    the actual answer will be accepted.*/

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int,vector<int>,greater<int>> high;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push(num);
        high.push(low.top());
        low.pop();
        if (low.size() < high.size()){
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        return low.size() > high.size() ? low.top() : ((double)low.top() + high.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */