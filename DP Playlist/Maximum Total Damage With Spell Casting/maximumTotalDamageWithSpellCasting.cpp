// Maximum Total Damage With Spell Casting : O(N∗N)

class Solution {
public:
    long long helper(vector<pair<int, long long>>& v, int index, vector<long long>& dp, int n)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        long long notTake = helper(v, index+1, dp, n);
        int i = index+1;
        while(i<n && v[i].first - v[index].first <=2)
        {
            i++;
        }

        long long take = v[index].second + helper(v, i, dp, n);

        return dp[index] = max(take, notTake);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> um;
        for(auto a: power)
        {
            um[a] += a;
        }
        vector<pair<int, long long>> v(um.begin(), um.end());
        sort(v.begin(), v.end());
        int n = v.size();

        vector<long long> dp(n, -1);

        return helper(v, 0, dp, n);
    }
};