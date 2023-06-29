/*

    Time Complexity : O(N^3), There are two nested loops, and substring computation at each iteration. Overall
    that results in O(N^3) time complexity.

    Space Complexity : O(N), Length of dp array is N+1.
    
    Solved using String + DP(Tabulation) + Hash Table.

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && set.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};