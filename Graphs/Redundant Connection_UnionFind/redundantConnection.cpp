// Redundant Connection

class Solution {
public:
    int find_op(int node, vector<int> &parent)
    {
        if(parent[node]==-1)
            return node;
        return parent[node] = find_op(parent[node], parent);
    }

    void union_op(int p1, int p2, vector<int> &parent, vector<int> &rank)
    {
        if(rank[p1] < rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p2] < rank[p1])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p2] = p1;
            rank[p2]++;
        }        
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1);
        vector<int> rank(edges.size()+1);
        vector<int> v1(2,0);
        for(int i=1;i<parent.size();i++)
        {
            parent[i] =-1;
            rank[i] = i;
        }

        for(auto a: edges)
        {
            int p1 = find_op(a[0], parent);
            int p2 = find_op(a[1], parent);
            if(p1!=p2)
            {
                union_op(p1, p2, parent, rank);
            }
            else
            {
                return a;
            }
        }
        
        return v1;
    }
};