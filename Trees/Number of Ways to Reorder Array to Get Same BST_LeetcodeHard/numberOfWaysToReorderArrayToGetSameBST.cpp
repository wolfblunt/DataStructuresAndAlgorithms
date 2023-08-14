// Number of Ways to Reorder Array to Get Same BST
// totalNoOfways = (n-1)C(left) * waysForLeft * waysForRight

class Solution {
public:
    long long mod = 1e9+7;
    vector<vector<long long>> table;

    // long long calculate_ncr(int n, int r)
    // {
    //     long long sum = 1;
    //     for(int j=1;j<=r;j++)
    //     {
    //         sum = sum % mod * (n-r+j) / j;
    //     }
    //     return sum % mod;
    // }

    long long dfs(vector<int>& nums)
    {
        int n = nums.size();

        if(n<=2)
        {
            return 1;
        }

        vector<int> left;
        vector<int> right;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i] < nums[0])
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }

        long long left_sol = dfs(left) % mod;
        long long right_sol = dfs(right) % mod;
        int left_len = left.size();
        return (((table[n - 1][left_len] * left_sol) % mod) * right_sol) % mod;
    }

    int numOfWays(vector<int>& nums)
    {
        int n = nums.size();
        table.resize(n + 1);
        // Pascal Triangle - for nCr
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        long long ans = dfs(nums) % mod;
        return (ans % mod - 1) % mod;
    }
};