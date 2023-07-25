// Maximum Number of Groups With Increasing Length

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        
        long long necessary = 1;
        long long total=0;
        long long ans=0;
        
        for(auto a: usageLimits)
        {
            total+=a;
            if(total >= necessary)
            {
                ans++;
                necessary += (ans+1);
            }
        }
        return ans;
    }
};