// Construct Product Matrix

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefixArr(n, vector<int>(m));
        vector<vector<int>> suffixArr(n, vector<int>(m));

        long long p = 1;
        int mod = 12345;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                prefixArr[i][j] = p;
                p = (p*grid[i][j]) % mod;
            }
        }

        p=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                suffixArr[i][j] = p;
                p = (p*grid[i][j]) % mod;
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long mul = (prefixArr[i][j] * suffixArr[i][j]) % mod;
                ans[i][j] = mul;
            }
        }

        return ans;
    }
};