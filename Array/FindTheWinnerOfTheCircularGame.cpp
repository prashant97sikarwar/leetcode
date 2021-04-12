//Problem Link:- https://leetcode.com/problems/find-the-winner-of-the-circular-game/

/* There are n friends that are playing a game. The friends are sitting in a circle and are 
numbered from 1 to n in clockwise order.
1. Start at the 1st friend.
2. Count the next k friends in the clockwise direction including the friend you started at. 
    The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4.  If there is still more than one friend in the circle, go back to step 2 starting from 
    the friend immediately clockwise of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n,int k){
        if (n == 1){
            return 1;
        }
        return (helper(n-1,k)+k-1)%n + 1;
    }
    
    int findTheWinner(int n, int k) {
        return helper(n,k);
    }
};