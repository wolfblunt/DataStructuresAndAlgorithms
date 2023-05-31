// Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        int s = flights.size();
        for(auto a: flights)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }
        queue<pair<int, pair<int, int>>> q; // {stops, node, cost}
        q.push({0, {src, 0}});
        vector<int> cost(n, 1e9);
        cost[src] = 0;

        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            int node = t.second.first;
            int c = t.second.second;
            int stop = t.first;

            if(stop > k)
                continue;

            for(auto a: adj[node])
            {
                int adjNode = a.first;
                int adjCost = a.second;
                if(c + adjCost < cost[adjNode] && stop<=k)
                {
                    cost[adjNode] = adjCost + c;
                    q.push({stop+1, {adjNode, adjCost + c}});
                }
            }
        }

        if(cost[dst] == 1e9)
        {
            return -1;
        }

        return cost[dst];
    }
};