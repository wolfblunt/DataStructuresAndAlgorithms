// Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

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

        if(pu==pv)
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
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int calcMST(int n, vector<vector<int>>& edges, int exclude, int include)
    {
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }

        int weight = 0;

        if(include != -1)
        {
            weight += edges[include][2];
            unionByRank(edges[include][0], edges[include][1]);
        }

        for(int i=0;i<edges.size();i++)
        {
            if(i == exclude)
            {
                continue;
            }

            if(findUltimateParent(edges[i][0]) != findUltimateParent(edges[i][1]))
            {
                unionByRank(edges[i][0], edges[i][1]);
                weight += edges[i][2];
            }
        }


        for(int i=0;i<n;i++)
        {
            if(findUltimateParent(i) != findUltimateParent(n-1))
            {
                return INT_MAX;
            }
        }

        return weight;
    }

    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }

        vector<int> critical;
        vector<int> pseudoCritical;

        sort(edges.begin(), edges.end(), cmp);

        int minCost = calcMST(n, edges, -1, -1);
        cout<<"MinCost : "<<minCost<<endl;
        for(int i=0;i<edges.size();i++)
        {
            if(minCost < calcMST(n, edges, i, -1))
            {
                critical.push_back(edges[i][3]);
            }
            else if(minCost == calcMST(n, edges, -1, i))
            {
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);
        return result;
    }
};