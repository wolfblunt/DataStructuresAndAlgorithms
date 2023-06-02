// Detonate the Maximum Bombs

class Solution {
public:
    void dfs(vector<vector<int>> &bombGraph, vector<int> &visited, int &ans, int node)
    {
        visited[node] = 1;
        ans++;
        for(auto a: bombGraph[node])
        {
            if(!visited[a])
            {
                dfs(bombGraph, visited, ans, a);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        int count = 0;
        vector<vector<int>> bombGraph(n);

        for(int i=0;i<n;i++)
        {
            long long x = bombs[i][0];
            long long y = bombs[i][1];
            long long r2 = (long long) bombs[i][2] * bombs[i][2];

            for(int j=0;j<n;j++)
            {
                if((x-bombs[j][0])*(x-bombs[j][0]) + ((y-bombs[j][1]))*((y-bombs[j][1])) <= r2)
                {
                    bombGraph[i].push_back(j);
                }
            }
        }

        
        for(int i=0;i<n && count<n;i++)
        {
            int ans = 0;
            vector<int> visited(n, 0);
            dfs(bombGraph, visited, ans, i);
            count = max(count, ans);
        }

        return count;
    }
};