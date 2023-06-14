// Collecting Chocolates

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = LONG_MAX;
        int n = nums.size();
        vector<int> checked(n, INT_MAX);
        vector<int> cnum(nums.begin(), nums.end());
        for(auto a: nums)
            cnum.push_back(a);

        for(int i=0;i<n;i++)
        {
            long long sum = 0;
            for(int j=0;j<n;j++)
            {
                checked[j] = min(checked[j], cnum[i+j]);
                sum+=checked[j];
            }

            sum += (long long)i*(long long)x;
            ans = min(ans, sum);
        }

        return ans;
    }
};