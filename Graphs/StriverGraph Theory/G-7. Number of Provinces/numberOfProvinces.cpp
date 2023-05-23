// Number of Provinces

class Solution {
public:
    void dfs(vector<int> &visited ,vector<vector<int>>& adj, int v)
    {
        visited[v] = 1;
        for(auto a: adj[v])
        {
            if(visited[a]==0)
            {
                dfs(visited, adj, a);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(visited, adj, i);
            }
        }
        return count;
    }
};