// Strongly Connected Components (Kosaraju's Algo)

// 3 steps Process:

// i) Sort all the edges according to finishing time.
// ii) Reverse the graph
// iii) Do a DFS
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	void dfs1(vector<vector<int>>& adj, vector<int> &visited, stack<int> &s, int node)
	{
	    visited[node] = 1;
	    
	    for(auto a: adj[node])
	    {
	        if(!visited[a])
	        {
	            dfs1(adj, visited, s, a);
	        }
	    }
	    
	    s.push(node);
	}
	
	void dfs2(vector<int> revAdj[], vector<int> &visited, int node)
	{
	    visited[node] = 1;
	    
	    for(auto a: revAdj[node])
	    {
	        if(!visited[a])
	        {
	            dfs2(revAdj, visited, a);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V, 0);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs1(adj, visited, s, i);
        }
        
        vector<int> revAdj[V];
        
        for(int i=0;i<V;i++)
        {
            visited[i] = 0;
            for(auto a: adj[i])
            {
                revAdj[a].push_back(i);
            }
        }
        
        int stronglyConnectedComponent = 0;
        
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if(!visited[node])
            {
                stronglyConnectedComponent++;
                dfs2(revAdj, visited, node);
            }
        }
        
        return stronglyConnectedComponent;
    }
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}