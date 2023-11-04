// Count Vowels Permutation

class Solution {
public:
    int mod = 1e9+7;

    int helper(int index, int vowel, vector<vector<int>> &dp, int &n)
    {
        if(index == n-1)
        {
            return 1;
        }
        if(dp[index][vowel] != -1)
        {
            return dp[index][vowel];
        }

        long long ans = 0;
        if(vowel == 0)
        {
            // 'a' may only be followed by an 'e'
            ans = (ans + helper(index+1, 1, dp, n)) % mod; 
        }
        if(vowel == 1)
        {
            // 'e' may only be followed by an 'a' or an 'i'
            ans = (ans + helper(index+1, 0, dp, n) + helper(index+1, 2, dp, n)) % mod;
        }
        if(vowel == 2)
        {
            // 'i' may not be followed by another 'i'
            ans = (ans + helper(index+1, 0, dp, n) + helper(index+1, 1, dp, n) + helper(index+1, 3, dp, n) + helper(index+1, 4, dp, n)) % mod;
        }
        if(vowel == 3)
        {
            // 'o' may only be followed by an 'i' or a 'u'
            ans = (ans + helper(index+1, 2, dp, n) + helper(index+1, 4, dp, n)) % mod;
        }
        if(vowel == 4)
        {
            // 'u' may only be followed by an 'a'
            ans = (ans + helper(index+1, 0, dp, n)) % mod;
        }

        return dp[index][vowel] = ans;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n, vector<int>(5, -1));  // (length, ends with ith vowel)
        
        long long ans = 0;
        for(int i=0;i<5;i++)
        {
            ans = (ans + helper(0,i,dp,n)) % mod;  // starting from length=0
        }

        return ans%mod;
    }
};