//problem Link:- https://leetcode.com/problems/sliding-window-maximum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> pq;
        for(int i=0;i<k;i++){
            while (!pq.empty() && nums[pq.back()] <= nums[i]){
                pq.pop_back();
            }
            pq.push_back(i);
        }
        vector<int> result;
        for(int i=k;i<nums.size();i++){
            result.push_back(nums[pq.front()]);
            while (!pq.empty() && nums[pq.back()] <= nums[i]){
                pq.pop_back();
            }
            while (!pq.empty() && pq.front() <= i-k){
                pq.pop_front();
            }
            pq.push_back(i);
        }
        result.push_back(nums[pq.front()]);
        return result;
    }
};