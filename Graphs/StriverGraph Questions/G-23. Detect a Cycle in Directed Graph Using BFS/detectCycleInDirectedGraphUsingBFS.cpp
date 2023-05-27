// Detect a Cycle in Directed Graph Using BFS

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto a: adj[i])
            {
                indegree[a]++;
            }
        }
        
        queue<int> q;
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto a: adj[node])
            {
                indegree[a]--;
                if(indegree[a]==0)
                {
                    q.push(a);
                }
            }
        }
        
        if(count!=V)
        {
            return true;
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