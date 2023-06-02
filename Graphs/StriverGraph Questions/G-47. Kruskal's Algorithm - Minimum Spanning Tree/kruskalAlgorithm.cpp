// Kruskal's Algorithm - Minimum Spanning Tree

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> parent;
	vector<int> rank;
	int findUltimateParent(int node)
	{
	    if(parent[node] == node)
	    {
	        return node;
	    }
	    return parent[node] = findUltimateParent(parent[node]);
	}
	
	void UnionByRank(int u, int v)
	{
	    int pu = findUltimateParent(u);
	    int pv = findUltimateParent(v);
	    
	    if(pu == pv)
	    {
	        return;
	    }
	    if(rank[pu] < rank[pv])
	    {
	        parent[pu] = pv;
	    }
	    else if(rank[pu] > rank[pv])
	    {
	        parent[pv] = pu;
	    }
	    else
	    {
	        parent[pv] = pu;
	        rank[u]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto a: adj[i])
            {
                int adjNode = a[0];
                int wt = a[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        int sum = 0;
        parent.resize(V);
        rank.resize(V);
        for(int i=0;i<V;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        for(auto a: edges)
        {
            int u = a.second.first;
            int v = a.second.second;
            int wt = a.first;
            
            if(findUltimateParent(u) != findUltimateParent(v))
            {
                sum += wt;
                UnionByRank(u,v);
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