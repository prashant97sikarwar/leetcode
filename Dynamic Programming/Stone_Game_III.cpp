//Problem Link:- https://leetcode.com/problems/stone-game-iii/

/*Alice and Bob continue their games with piles of stones. There are several stones arranged 
in a row, and each stone has an associated value which is an integer given in the array 
stoneValue.Alice and Bob take turns, with Alice starting first. On each player's turn, that 
player can take 1, 2 or 3 stones from the first remaining stones in the row.The score of each
player is the sum of values of the stones taken. The score of each player is 0 initially.The 
objective of the game is to end with the highest score, and the winner is the player with the 
highest score and there could be a tie. The game continues until all the stones have been 
taken.Assume Alice and Bob play optimally.Return "Alice" if Alice will win, "Bob" if Bob will 
win or "Tie" if they end the game with the same score.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[50001];
    int helper(vector<int> &s,int i){
        if (i >= s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        else{
            int ans = INT_MIN;
            ans = max(ans,s[i] - helper(s,i+1));
            if (i+1 < s.size())
                ans = max(ans,s[i] + s[i+1] - helper(s,i+2));
            if (i+2 < s.size())
                ans = max(ans,s[i] + s[i+1] + s[i+2] - helper(s,i+3));
            
            return dp[i] = ans;
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        for(int i=0;i<stoneValue.size();i++)
            dp[i] = -1;
        int alice = helper(stoneValue,0);
        if (alice == 0)
            return "Tie";
        else if (alice > 0)
            return "Alice";
        else
            return "Bob";
    }
};