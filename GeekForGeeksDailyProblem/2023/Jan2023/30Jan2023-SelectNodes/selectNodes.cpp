// Select Nodes

#include<bits/stdc++.h> 
using namespace std; 

class Solution{
  public:
    int dfs(vector<vector<int>> &adj, vector<int> &vis, int index, int &ans)
    {
        if(vis[index])
            return 0;
        
        vis[index] = 1;
        int isLightUp = 0;
        for(auto a: adj[index])
        {
            if(!vis[a])
            {
                int temp = dfs(adj, vis, a, ans);
                if(temp==0)
                    isLightUp = 1;
            }
        }
        if(isLightUp)
            ans+=1;
        
        return isLightUp;
    }
    
    int countVertex(int N, vector<vector<int>>edges){
        vector<vector<int>> adj(N+1);
        vector<int> vis(N+1,0);
        for(auto a: edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        
        int ans = 0;
        dfs(adj, vis, 1, ans);
        return ans;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 