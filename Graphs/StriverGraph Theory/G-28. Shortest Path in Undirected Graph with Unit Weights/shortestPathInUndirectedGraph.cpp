// Shortest path in Undirected Graph having unit distance

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        vector<int> distance(N,1e9);
        distance[src] = 0;
        
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto a: adj[node])
            {
                if(distance[node]+1 < distance[a])
                {
                    distance[a] = distance[node] + 1;
                    q.push(a);
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}