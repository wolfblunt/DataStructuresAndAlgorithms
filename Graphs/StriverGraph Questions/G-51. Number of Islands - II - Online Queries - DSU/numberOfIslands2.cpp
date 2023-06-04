// Number Of Islands 2

#include <bits/stdc++.h>
using namespace std;

class Solution {
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
    
    void unionOp(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv)
            return;
        
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
            rank[pu]++;
        }
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> visited(n, vector<int>(m,0));
        parent.resize(n*m);
        rank.resize(n*m);
        
        for(int i=0;i<n*m;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        int count = 0;
        vector<int> ans;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto a: operators)
        {
            int r = a[0];
            int c = a[1];
            
            if(visited[r][c] == 1)
            {
                ans.push_back(count);
                continue;
            }
            visited[r][c] = 1;
            count++;
            
            for(auto a: dir)
            {
                int adjr = r + a[0];
                int adjc = c + a[1];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc <m)
                {
                    if(visited[adjr][adjc] == 1)
                    {
                        int nodeNo = r*m + c;
                        int adjNodeNo = adjr*m + adjc;
                        if(findUltimateParent(nodeNo) != findUltimateParent(adjNodeNo))
                        {
                            count--;
                            unionOp(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}