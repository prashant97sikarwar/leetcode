//Problem Link:- https://leetcode.com/problems/reconstruct-itinerary/

/*given a list of airline tickets represented by pairs of departure and arrival airports 
[from, to], reconstruct the itinerary in order. All of the tickets belong to a man who 
departs from JFK. Thus, the itinerary must begin with JFK.there are multiple valid 
itineraries, you should return the itinerary that has the smallest lexical order when 
read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical 
order than ["JFK", "LGB"].All airports are represented by three capital letters 
(IATA code).You may assume all tickets form at least one valid itinerary.One must use all 
the tickets once and only once.*/
#include<bits/stdio.h>
using namespace std;

vector<string> findItinerary(vector<vector<string>> tickets) {
    unordered_map<string, multiset<string>> graph;
    for (auto ticket : tickets) {
        graph[ticket[0]].insert(ticket[1]);
    }
    vector<string> res;
    stack<string> q;
    q.push("JFK");
    while (!q.empty()) {
        auto from = q.top();
        if (!graph[from].size()) {
            res.push_back(from);
            q.pop();
        } else {
            auto to = graph[from].begin();
            q.push(*to);
            graph[from].erase(to);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

