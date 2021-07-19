//Problem link:- https://leetcode.com/problems/insert-delete-getrandom-o1/

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)){
            return false;
        }
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()){
            return false;
        }
        int idx = mp[val];
        int vic = nums[nums.size()-1];
        swap(nums[idx],nums[nums.size()-1]);
        nums.pop_back();
        mp[vic] = mp[val];
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};
