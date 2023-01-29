// Minimum Time to Collect All Apples in a Tree

class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int prev, int current)
    {
        int time = 0;
        for(auto a: adj[current])
        {
            if(a!=prev)
            {
                int res = dfs(adj, hasApple, current, a);
                if(res > 0 || hasApple[a])
                {
                    time += (res+2);
                }
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto a: edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        return dfs(adj, hasApple, -1, 0);
    }
};