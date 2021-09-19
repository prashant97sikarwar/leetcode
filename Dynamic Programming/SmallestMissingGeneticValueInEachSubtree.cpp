//Problem link;- https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        vector<int> graph[100005];
        unordered_set<int> visited;
        
public:
    void dfs(int node,vector<int>&nums){
        for(int child : graph[node]){
            if (visited.count(nums[child]) == 0){
                visited.insert(nums[child]);
                dfs(child,nums);
            }
        }
    }
    
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        const int n = nums.size();
        int missing  = 1;
        for(int i=1;i<n;i++){
            graph[parents[i]].push_back(i);
        }
        int node = -1;
        vector<int> result(n,1);
        for(int i=0;i<n;i++){
            if (nums[i] == 1){
                node = i;
                break;
            }
        }
        if (node == -1){
            return result;
        }
        while (node != -1){
            visited.insert(nums[node]);
            dfs(node,nums);
            while (visited.count(missing)){
                missing++;
            }
            result[node] = missing;
            node = parents[node];
        }
        return result;
    }
};