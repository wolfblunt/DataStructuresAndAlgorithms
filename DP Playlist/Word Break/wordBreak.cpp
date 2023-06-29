// Word Break

/*

    Time Complexity : O(N^3), Size of recursion tree can go up to N^2.

    Space Complexity : O(N), The depth of the recursion tree can go upto N.
    
    Solved using String + DP(Memoisation) + Hash Table.

*/

class Solution {
public:
    bool helper(string s, unordered_set<string> &set, vector<int>& dp, int start)
    {
        if(start == s.size())
        {
            return true;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }

        for(int i=start; i<s.size();i++)
        {
            if(set.count(s.substr(start, i-start+1)) && helper(s, set, dp, i+1))
            {
                dp[start] = true;
                return true;
            }
        }
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return helper(s, set, dp, 0);
    }
};