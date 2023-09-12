// Min Cost to Connect All Points

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u)
    {
        if(parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void unionFunc(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

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
            parent[pv] = pu;
            rank[u]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = i;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    pq.push({dis, i, j});
                }
            }
        }

        int totalCost = 0;
        int index = 0;

        while(index < n-1)
        {
            vector<int> v = pq.top();
            int p1 = find(v[1]);
            int p2 = find(v[2]);
            pq.pop();

            if(p1 != p2)
            {
                parent[p1]  = p2;
                totalCost += v[0];
                index++;
            }
        }

        return totalCost;
    }
};