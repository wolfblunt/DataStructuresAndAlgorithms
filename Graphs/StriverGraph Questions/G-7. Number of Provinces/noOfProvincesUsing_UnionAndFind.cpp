// No of Provinces

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
    
    int numProvinces(vector<vector<int>> isConnected, int V) {
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        parent.resize(V);
        rank.resize(V);
        
        for(int i=0;i<V;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        for(int i=0;i<V;i++)
        {
            for(auto a: adj[i])
            {
                int node = i;
                int adjNode = a;
                unionOp(node, adjNode);
            }
        }
        
        int count = 0;
        for(int i=0;i<V;i++)
        {
            if(parent[i] == i)
            {
                count++;
            }
        }
        return count;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}