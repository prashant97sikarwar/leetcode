//Problem Link:- https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

#include<bits/stdc++.h>
using namespace std;


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    unordered_map<int,set<int>> mp;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
       if (mp.find(val) != mp.end()){
            mp[val].insert(nums.size());
            nums.push_back(val);
            return false;
        }
        mp[val].insert(nums.size());
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it=mp.find(val);
        if(it!=mp.end())
        {
            auto font=*it->second.begin();//get the index of removal element
            mp[val].erase(it->second.begin()); //erase it from map

          nums[font]=nums.back(); //put the last elemnt at font index
          mp[nums.back()].insert(font); //insert in set that index font
          mp[nums.back()].erase(nums.size() - 1); 
          nums.pop_back(); //remove last element
            if(it->second.size()==0) //if it empty
                mp.erase(it);
            return 1;
        }
        return 0;
    
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};
