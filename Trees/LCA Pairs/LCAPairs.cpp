// LCA Pairs - https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-115/problems

class Solution 
{
    public:
	void dfs(int u, vector<long long> &subTree, vector<vector<int>> &adj, vector<long long> &ans) 
	{
	    int sub = 1;
        for (int v : adj[u]) 
        {
            dfs(v,subTree,adj,ans);
            ans[u] += subTree[v]*sub;
            sub+=subTree[v];
        }
        subTree[u] = sub;
    }
	
	vector<long long>calcPairs(int N, vector<int> p)
	{
	    vector<vector<int>> adj(N);
	    
	    for (int i = 1; i < N; ++i) {
	        adj[p[i]].push_back(i);
	    }
	 
	    vector<long long> ans(N, 1);
	    vector<long long> subTree(N, 0);
	    
	    dfs(0, subTree, adj, ans);
	    
	    return ans;
	}
};