// Minimum Spanning Tree - Prim's Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {weight, node}
        vector<int> visited(V, 0);
        pq.push({0, 0}); // {weight, node}
        
        int sum = 0;
        while(!pq.empty())
        {
            auto element = pq.top();
            int wt = element.first;
            int node = element.second;
            pq.pop();
            if(visited[node] == 1)
                continue;
            
            visited[node] = 1;
            sum += wt;
            for(auto a: adj[node])
            {
                int adjNode = a[0];
                int adjWt = a[1];
                if(!visited[adjNode])
                {
                    pq.push({adjWt, adjNode});
                }
                
            }
        }
        
        return sum;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}