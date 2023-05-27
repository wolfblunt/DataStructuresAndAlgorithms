// Shortest path in Directed Acyclic Graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void topoSort(vector<pair<int,int>> adj[], vector<int> &visited, stack<int> &s, int node)
    {
        visited[node] = 1;
        
        for(auto a: adj[node])
        {
            if(!visited[a.first])
            {
                topoSort(adj, visited, s, a.first);
            }
        }
        
        s.push(node);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int> visited(N,0);
        stack<int> s;
        
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                topoSort(adj, visited, s, i);
            }
        }
        
        vector<int> distance(N,1e9);
        distance[0] = 0;
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            for(auto a: adj[node])
            {
                int v = a.first;
                int w = a.second;
                if(distance[node] + w < distance[v])
                {
                    distance[v] = distance[node] + w;
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(distance[i]==1e9)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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