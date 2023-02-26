// Number of Good Components
 
class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int &vertices, int &edges)
    {
        vertices++;
        vis[node]=1;
        
        for(auto i:adj[node])
        {
            edges++;
            if(!vis[i])
            dfs(i,vis,adj,vertices,edges);
        }
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<int>vis(V+1,0);
        int ans=0;
        int i;
        for(i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                int edges=0;
                int vertices=0;
                dfs(i,vis,adj,vertices,edges);
                if(vertices*(vertices-1)==edges) ans++;
            }
        }
        return ans;
    }
};