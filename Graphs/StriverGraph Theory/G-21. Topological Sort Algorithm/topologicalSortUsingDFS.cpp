// Topological sort

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(vector<int> adj[], vector<int> &visited, stack<int> &s, int node)
	{
	    visited[node] = 1;
	    
	    for(auto a: adj[node])
	    {
	        if(!visited[a])
	        {
	            dfs(adj, visited, s, a);
	        }
	    }
	    
	    s.push(node);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0);
	    stack<int> s;
	    
	    vector<int> result;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(adj, visited, s, i);
	        }
	    }
	    
	    while(!s.empty())
	    {
	        result.push_back(s.top());
	        s.pop();
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}