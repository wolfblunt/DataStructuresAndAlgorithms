// Connecting the graph

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
    
    int Solve(int V, vector<vector<int>>& edges) 
    {
        int countExtraEdges = 0;
        parent.resize(V);
        rank.resize(V);
        
        for(int i=0;i<V;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        for(auto a: edges)
        {
            int u = a[0];
            int v = a[1];
            if(findUltimateParent(u) == findUltimateParent(v))
            {
                countExtraEdges++;
            }
            else
            {
                unionOp(u,v);
            }
        }
        
        int noOfComponents = 0;
        for(int i=0;i<V;i++)
        {
            if(parent[i] == i)
            {
                noOfComponents++;
            }
        }
        
        int ans = noOfComponents - 1;
        if(ans <= countExtraEdges)
        {
            return ans;
        }
        return -1;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}