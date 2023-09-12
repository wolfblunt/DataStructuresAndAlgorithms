// Mother Vertex

class Solution 
{
    public:
    bool  dfs(vector<int>adj[], int node, vector<int> &visited)
    {
        visited[node] = true;
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                dfs(adj,a,visited);
            }
        }
    }
    
    
    //Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int>adj[])
    {
        vector<int> visited(V, 0);
        int ans = -1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(adj, i, visited);
                ans = i;
            }
        }
       // cout<<"ans: "<<ans<<endl;
        
        visited.assign(V, 0);
        dfs(adj,ans,visited);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                return -1;
            }
        }
        
        return ans;
        
    }

};