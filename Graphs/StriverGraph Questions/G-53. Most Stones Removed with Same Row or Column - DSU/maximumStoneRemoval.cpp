// Maximum Stone Removal

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
    
    void unionByRank(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        
        if(pu == pv)
            return;
        
        if(rank[pu]<rank[pv])
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
    
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto a: stones)
        {
            maxRow = max(maxRow, a[0]);
            maxCol = max(maxCol, a[1]);
        }
        
        int disSize = maxRow+maxCol+2;
        parent.resize(disSize);
        rank.resize(disSize);
        for(int i=0;i<disSize;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }
        
        unordered_map<int, int> um;
        
        for(auto a: stones)
        {
            int nodeRow = a[0];
            int nodeCol = maxRow + a[1] + 1;
            unionByRank(nodeRow, nodeCol);
            um[nodeRow] = 1;
            um[nodeCol] = 1;
        }
        
        int countComponent = 0;
        for(auto a: um)
        {
            if(findUltimateParent(a.first) == a.first)
            {
                countComponent++;
            }
        }
        
        return n - countComponent;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}