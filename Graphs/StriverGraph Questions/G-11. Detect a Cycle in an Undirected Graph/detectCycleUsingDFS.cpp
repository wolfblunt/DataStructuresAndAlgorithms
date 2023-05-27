#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void isDetectdfs(int node, vector<int> adj[], vector<int> &visited, bool &flag, int parent)
    {
        if(visited[node])
            return;
            
        visited[node] = true;
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                isDetectdfs(a, adj, visited, flag, node);
            }
            else
            {
                if(parent==a)
                {
                    continue;
                }
                else
                {
                    flag = true;
                    return;
                }
            }
        }
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> visited(v, false);
        bool flag = false;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                isDetectdfs(i, adj, visited, flag, -1);
                if(flag)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}