// Density Of A Tree

class Solution{
    public:
    void dfs(vector<vector<int>> &adj, int d, int& height, int src)
    {
        height = max(height, d);
        
        for(auto a: adj[src])
        {
            dfs(adj, d+1, height, a);
        }
    }
    
    long double density(int N, vector<int> par){
        vector<vector<int>> adj(N);
        for(int i=1;i<N;i++)
        {
            adj[par[i]].push_back(i);
        }
        int height = 0;
        dfs(adj, 1, height, 0);
        return (long double)N/(long double)height;
    }
};