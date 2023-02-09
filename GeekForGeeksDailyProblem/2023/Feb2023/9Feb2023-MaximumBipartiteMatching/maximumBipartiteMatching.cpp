// Maximum Bipartite Matching

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>&G, vector<int> &match, vector<bool> &visited, int index)
    {
        for(int i=0;i<G[0].size();i++)
        {
            if(G[index][i]==1 && !visited[i])
            {
                visited[i]=true;
                if(match[i]==-1)
                {
                    match[i]=index;
                    return true;
                }
                else if(dfs(G, match, visited, match[i]))
                {
                    match[i] = index;
                    return true;
                }
            }
        }
        return false;
    }
    
	int maximumMatch(vector<vector<int>>&G){
	    int m = G.size();  // number of persons
	    int n = G[0].size();  // number of Jobs
	    vector<int> match(n,-1);
	    int result=0;
	    
	    for(int i=0;i<m;i++)
	    {
	        vector<bool> visited(n,false);
	        if(dfs(G, match, visited, i))
	        {
	            result++;
	        }
	    }
	    return result;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}