// Number of Ways to Arrive at Destination -  O(E + V log V)

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq; // {time, node}
        vector<int> ways(n, 0);
        vector<long long> time(n, LLONG_MAX);
        int mod = (int)(1e9+7);
        vector<pair<long long,long long>> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
            adj[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
        }
        
        pq.push({0, 0});
        ways[0] = 1;
        time[0] = 0;
        while(!pq.empty())
        {
            auto element = pq.top();
            pq.pop();
            int node = element.second;
            int t = element.first;
            
            for(auto a: adj[node])
            {
                int new_node = a.first;
                if(t + a.second < time[new_node])
                {
                    pq.push({t + a.second, new_node});
                    time[new_node] = t + a.second;
                    ways[new_node] = (ways[node])%mod;
                }
                
                else if(t + a.second == time[new_node])
                {
                    ways[new_node] = (ways[new_node] + ways[node])%mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}