// Minimum Deletions to Make String K-Special - O(26*26) + O(26*log26)

class Solution {
public:
    int helper(int i, int j, vector<int> &freq, int k, vector<vector<int>> &dp)
    {
        if(i==j || freq[j] - freq[i] <= k)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        return dp[i][j] = min(freq[i] + helper(i+1, j, freq, k, dp), freq[j]-freq[i]-k + helper(i, j-1, freq, k, dp));
    }

    int minimumDeletions(string word, int k) {
        int n = word.length();
        vector<int> freq(26, 0);
        for(int i=0;i<n;i++)
        {
            freq[word[i]-'a']++;
        }

        sort(freq.begin(), freq.end());

        vector<vector<int>> dp(26, vector<int>(26, -1));
        return helper(0, 25, freq, k, dp);
    }
};