//Problem Link:- https://leetcode.com/problems/my-calendar-i/

#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
    private:
    map<int,int> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(end);
        if (it == mp.begin()){
            mp[start] = end;
            return true;
        }
        it = prev(it);
        if (it->second <= start){
            mp[start] = end;
            return true;
        }
        return false;
    }
};
