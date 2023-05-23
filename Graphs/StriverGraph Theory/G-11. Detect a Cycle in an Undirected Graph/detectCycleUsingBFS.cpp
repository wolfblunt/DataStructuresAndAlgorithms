// Detect Cycle in Undirected Graph

bool cycleDetect(int A, vector<vector<int> > &B, vector<bool>& visited, int source)
{
    visited[source] = true;
    queue<pair<int,int>> q;
    q.push({source,-1});
    
    while(!q.empty())
    {
        int parent = q.front().second;
        int node = q.front().first;
        q.pop();
        for(auto a: B[node])
        {
            if(!visited[a])
            {
                q.push({a, node});
                visited[a] = true;
            }
            else if(parent != a)
            {
                return true;
            }
        }
    }
    return false;
}

int solve(int v, vector<vector<int> > &B)
{
    vector<bool> visited(v+1, false);
    vector<vector<int>> adj(v);
    for(auto a: B)
    {
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(cycleDetect(v, adj, visited, i))
            {
                return 1;
            }
        }
    }
    return 0;
}