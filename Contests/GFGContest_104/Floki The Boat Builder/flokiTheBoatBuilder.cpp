// Floki The Boat Builder

class Solution{

	public:
	void find(int s, int d, vector<vector<int>>& adj, int &flag)
	{
	    if(s==d)
	        flag = 1;

	   for(auto a: adj[s])
	   {
	       find(a,d,adj,flag);
	   }
	}
	
	int gcd(int a, int b)
	{
	    while(a%b>0)
	    {
	        int temp = a%b;
	        a = b;
	        b = temp;
	    }
	    return b;
	}
	
	void dfsGCD(int s, vector<vector<int>>& adj, int &gccd, vector<int>& v)
	{
	    gccd = gcd(gccd, v[s]);
	    for(auto a: adj[s])
	    {
	        dfsGCD(a, adj, gccd, v);
	    }
	}
	
	
	int gcdTree(int n, vector<vector<int>> &edges, vector<int> &val, int x, int y)
	{
		vector<vector<int>> adj(n);
		for(int i=0;i<edges.size();i++)
		{
		    adj[edges[i][0]].push_back(edges[i][1]);
		}
		
		int flag = 0;
		int gcddX = val[x];
		int gcddY = val[y];
		find(x,y,adj,flag);
		find(y,x,adj,flag);
		if(flag)
		{
		    return -1;
		}
		dfsGCD(x, adj, gcddX, val);
		dfsGCD(y, adj, gcddY, val);
		
		return gcd(gcddX, gcddY);
	}
};