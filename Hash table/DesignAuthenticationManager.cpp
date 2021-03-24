//Problem Link :- https://leetcode.com/problems/design-authentication-manager/

/*Implement the AuthenticationManager class:
1. AuthenticationManager(int timeToLive) constructs the AuthenticationManager and sets the 
    timeToLive.
2. generate(string tokenId, int currentTime) generates a new token with the given tokenId at 
    the given currentTime in seconds.
3. renew(string tokenId, int currentTime) renews the unexpired token with the given tokenId 
    at the given currentTime in seconds. If there are no unexpired tokens with the given 
    tokenId, the request is ignored, and nothing happens.
4. countUnexpiredTokens(int currentTime) returns the number of unexpired tokens at the given 
    currentTime.
*/

#include<bits/stdc++.h>
using namespace std;

class AuthenticationManager {
    int ttl;
    unordered_map<string,int> tokens;
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        auto tokenIt = tokens.find(tokenId);
        if (tokenIt != end(tokens) && tokenIt->second > currentTime) {
            tokenIt->second = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for(auto token : tokens){
            if (token.second > currentTime)
                res++;
        }
        return res;
    }
};