// Detect cycle in Directed Graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfsCycleCheck(vector<int> adj[], vector<int> &visited, vector<int> &pathVisited, int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                if(dfsCycleCheck(adj, visited, pathVisited, a) == true)
                {
                    return true;
                }
            }
            
            else if(visited[a] && pathVisited[a])
            {
                return true;
            }
        }
        
        pathVisited[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfsCycleCheck(adj, visited, pathVisited, i))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}