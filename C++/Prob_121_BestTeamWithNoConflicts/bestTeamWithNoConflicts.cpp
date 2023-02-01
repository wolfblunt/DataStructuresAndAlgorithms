// Best Team With No Conflicts

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> v;
        int n = scores.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({ages[i], scores[i]});
        }

        sort(v.begin(), v.end(), greater<>());
        vector<int> dp(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int score = v[i][1];
            dp[i] = score;
            for(int j=0;j<i;j++)
            {
                if(v[j][1] >= score)
                {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};