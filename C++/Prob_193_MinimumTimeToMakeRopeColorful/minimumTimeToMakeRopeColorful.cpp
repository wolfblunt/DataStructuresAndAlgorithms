// Minimum Time to Make Rope Colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i=0;
        int ans = 0;
        while(i<n)
        {
            int j=i;
            int sum = 0;
            int maxx = 1;
            for(;i<n && colors[i]==colors[j];i++)
            {
                sum+=neededTime[i];
                maxx = max(maxx, neededTime[i]);
            }
            sum -= maxx;
            ans += sum;
        }

        return ans;
    }
};