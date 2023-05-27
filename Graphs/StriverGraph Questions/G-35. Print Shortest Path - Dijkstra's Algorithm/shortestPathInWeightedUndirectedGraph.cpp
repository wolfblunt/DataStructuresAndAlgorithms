// Shortest Path in Weighted undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> distance(n+1, 1e9);
        distance[1] = 0;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({distance[1], 1});
        
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
        }
        
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int dist = it.first;
            
            for(auto a: adj[node])
            {
                int v = a.first;
                int w = a.second;
                
                if(dist + w < distance[v])
                {
                    distance[v] = dist + w;
                    parent[v] = node;
                    pq.push({distance[v], v});
                }
            }
        }
        
        if(distance[n] == 1e9)
        {
            return {-1};
        }
        
        vector<int> path;
        int node = n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}