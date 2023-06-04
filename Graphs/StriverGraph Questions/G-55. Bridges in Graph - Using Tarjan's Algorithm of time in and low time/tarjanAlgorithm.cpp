// Bridge In a Graph - Tarjan's Algorithm

// to check bridge: low[neighbor] > discoveryTime[node]
// condition for back edge: low[node] = min(low[node], discoveryTime[neighbor])

class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &visited, vector<int> &discoveryTime, vector<int> &low,vector<int> adj[], vector<vector<int>> &bridges)
    {
        visited[node] = 1;
        discoveryTime[node] = timer;
        low[node] = timer;
        timer++;
        for(auto a: adj[node])
        {
            if(a == parent)
            {
                continue;
            }

            if(visited[a] == 0)
            {
                dfs(a, node, visited, discoveryTime, low, adj, bridges);
                low[node] = min(low[node], low[a]);

                // Checking condition for bridge
                if(low[a] > discoveryTime[node])
                {
                    bridges.push_back({a, node});
                }
            }
            else // Back Edge condition
            {
                low[node] = min(low[node], discoveryTime[a]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];

        for(auto a: connections)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        vector<int> discoveryTime(n,0);
        vector<int> low(n);  // earliest possible time
        vector<int> visited(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, visited, discoveryTime, low, adj, bridges);

        return bridges;
    }
};