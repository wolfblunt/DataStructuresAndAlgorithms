// Binary Trees With Factors

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> s(arr.begin(), arr.end());
        unordered_map<int, int> dp; // where each key is a number from arr and its value represents the number of binary trees with that number as the root.
        int MOD = 1e9 + 7;
        for(int a:arr)
        {
            dp[a] = 1; // Initialize each number's count to 1 to account for a single-node tree.
        }

        for(auto i: arr)
        {
            for(auto j: arr)
            {
                if(j > sqrt(i))
                {
                    break;
                }
                if(i%j == 0 && s.find(i/j) != s.end())
                {
                    long long temp = (long long)dp[j] * dp[i/j];
                    if(i/j == j)
                    {
                        dp[i] = (dp[i] + temp) % MOD;
                    }
                    else
                    {
                        dp[i] = (dp[i] + temp*2) % MOD;
                    }
                }
            }
        }

        int result = 0;
        for(auto a: dp)
        {
            result = (result + a.second) % MOD;
        }

        return  result;
    }
};