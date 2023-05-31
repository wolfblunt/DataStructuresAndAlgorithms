// Path With Minimum Effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        q.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        int dr = n-1;
        int dc = m-1;
        vector<vector<int>> t = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            auto record = q.top();
            q.pop();
            int r = record.second.first;
            int c = record.second.second;
            int diff = record.first;

            if(r == n-1 && c== m-1)
            {
                return diff;
            }

            for(auto a: t)
            {
                int nr = a[0] + r;
                int nc = a[1] + c;
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if(newEffort < dis[nr][nc])
                    {
                        dis[nr][nc] = newEffort;
                        q.push({newEffort, {nr, nc}});
                    }
                }
            }
        } 
        return 0; // untraceable
    }
};