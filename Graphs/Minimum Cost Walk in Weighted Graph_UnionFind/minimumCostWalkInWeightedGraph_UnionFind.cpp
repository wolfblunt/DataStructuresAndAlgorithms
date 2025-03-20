// Minimum Cost Walk in Weighted Graph  - O(N+M+Q)

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int findUltimateParent(int u)
    {
        if(parent[u] == u)
        {
            return u;
        }

        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu == pv)
        {
            return;
        }

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
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n);

        vector<int> componentSize(n, INT_MAX);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }

        for(auto a: edges)
        {
            unionByRank(a[0], a[1]);
        }

        for(auto a: edges)
        {
            int parentNode = findUltimateParent(a[0]);
            componentSize[parentNode] &= a[2];
        }

        vector<int> ans;
        for(auto& a: query)
        {
            int src = a[0];
            int dest = a[1];

            if(findUltimateParent(src) != findUltimateParent(dest))
            {
                ans.push_back(-1);
            }
            else
            {
                int parentNode = findUltimateParent(src);
                ans.push_back(componentSize[parentNode]);
            }
        }

        return ans;
    }
};