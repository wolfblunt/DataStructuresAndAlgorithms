#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> g; 
void dfs(int s)
{
	visited[s] = true;
	cout<<s<<" ";
	for(auto i:g[s])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	g.assign(n, vector<int>());
	visited.assign(n, false);
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int source;
	cin>>source;
	// for(int i=0;i<n;i++)
	// {
	// 	if(!visited[i])
	// 	{
	// 		dfs(i);
	// 	}
	// }
	dfs(source);

	return 0;
}