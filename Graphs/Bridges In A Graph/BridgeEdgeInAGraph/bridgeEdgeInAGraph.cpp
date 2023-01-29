// Given a Graph of V vertices and E edges and another edge(c - d), the task 
// is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	void dfs(int node, int parent, int &timer, vector<int> adj[], vector<int> &discovery, vector<int> &lowDiscovery, unordered_map<int, bool> &visited, int &finalanswer, int c, int d)
    {
        visited[node] = true;
        discovery[node] = lowDiscovery[node] = timer++;
        for(auto neighbor: adj[node])
        {
            if(neighbor==parent)
            {
                continue;
            }
            if(!visited[neighbor])
            {
                dfs(neighbor, node, timer, adj, discovery, lowDiscovery, visited, finalanswer, c,d);
                lowDiscovery[node] = min(lowDiscovery[node], lowDiscovery[neighbor]);
                // check edge is bridge
                if(lowDiscovery[neighbor] > discovery[node])
                {
                    if((node==c && neighbor==d) || (node == d && neighbor == c))
                    {
                        finalanswer=1;
                    }
                }
            }
            else
            {
                // for back edges
                lowDiscovery[node] = min(lowDiscovery[node], discovery[neighbor]);
            }
        }
    }
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        vector<int> discovery(v,-1);
        vector<int> lowDiscovery(v,-1);
        unordered_map<int, bool> visited;
        int parent=-1;
        int timer=0;
        int finalanswer=0;
        // DFS
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i, parent, timer, adj, discovery, lowDiscovery, visited, finalanswer, c, d);
            }
        }
        return finalanswer;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}