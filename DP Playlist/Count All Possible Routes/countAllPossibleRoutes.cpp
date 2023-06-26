// Count All Possible Routes

class Solution {
public:
    const int mod = 1e9+7;

    int helper(vector<int>& locations, int city, int finish, int remainFuel, vector<vector<int>>& dp)
    {  
        // base case
        if(remainFuel < 0)
        {
            return 0;
        }
        if(dp[city][remainFuel]!=-1)
        {
            return dp[city][remainFuel];
        }

        int total = city==finish ? 1 : 0;
        for(int nextCity=0;nextCity<locations.size();nextCity++)
        {
            if(nextCity != city && remainFuel >= abs(locations[city] - locations[nextCity]))
            {
                total = (total + helper(locations, nextCity, finish, remainFuel - abs(locations[city] - locations[nextCity]), dp)) % mod;
            }
        }

        return dp[city][remainFuel] = total;

    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
        return helper(locations, start, finish, fuel, dp);
    }
};