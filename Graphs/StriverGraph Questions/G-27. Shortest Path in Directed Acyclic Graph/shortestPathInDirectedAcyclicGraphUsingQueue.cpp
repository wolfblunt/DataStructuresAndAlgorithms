// Shortest path in Directed Acyclic Graph - Using Queue

class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto a: edges)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }
        
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++)
        {
            for(auto a: adj[i])
            {
                indegree[a.first]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> topoSort;
        while(!q.empty())
        {
            int node = q.front();
            topoSort.push_back(node);
            q.pop();
            for(auto a: adj[node])
            {
                indegree[a.first]--;
                if(indegree[a.first] == 0)
                {
                    q.push(a.first);
                }
            }
        }
        
        vector<int> distance(V,1e8);
        distance[0] = 0;
        for(int i=0;i<topoSort.size();i++)
        {
            for(auto a: adj[i])
            {
                if(distance[i] + a.second < distance[a.first])
                {
                    distance[a.first] = distance[i] + a.second;
                }
            }
        }
        
        for(int i=0;i<V;i++)
        {
            if(distance[i] == 1e8)
            {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};