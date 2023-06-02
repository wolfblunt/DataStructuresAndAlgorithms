// Santa Banta

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> prime;
    void precompute()
    {
        vector<bool> isPrime(1e6+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2;i<1e6;i++)
        {
            if(isPrime[i])
            {
                prime.push_back(i);
                for(int j=2*i;j<1e6;j=j+i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int &ans, int node)
    {
        visited[node] = 1;
        ans++;
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                dfs(adj, visited, ans, a);
            }
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        if(m==0)
            return -1;
        vector<int> visited(n+1,0);
        vector<int> adj[n+1];
        
        int maxCount = 0;
        
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                int ans = 0;
                dfs(g, visited, ans, i);
                maxCount = max(ans, maxCount);
            }
        }
        
        return prime[maxCount-1];
    }
};


int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}