//  Special Permutations

class Solution {
public:
    int mod = 1e9+7;
    long long dp[1<<14][15];

    int setBit(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            if (x & 1)
                ans++;
            x = x >> 1;
        }
        return ans;
    }

    int helperFunc(int idx, vector<int> &nums, int mask, int prev)
    {
        if(idx == nums.size())
        {
            return (setBit(mask) == nums.size());
        }

        if (dp[mask][prev+1] != -1)
        {
            return dp[mask][prev+1];
        }

        long long ways = 0;

        if(prev == -1)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (mask & (1 << i))
                    continue;
                else
                {
                    int newMask = mask | (1 << i);
                    ways =(ways + helperFunc(idx + 1, nums, newMask, i)) % mod;
                }
            }
        }
        else
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (mask & (1 << i))
                    continue;
                else
                {
                    if (nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0)
                    {
                        int newMask = mask | (1 << i);
                        ways = (ways + helperFunc(idx + 1, nums, newMask, i)) % mod;
                    }
                }
            }
        }

        return dp[mask][prev+1] = (ways) % mod;
    }

    int specialPerm(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int mask = 0;
        return helperFunc(0, nums, mask, -1) % mod;
    }
};