// Minimum Cost to Convert String I

class Solution {
public:
    void bfs(unordered_map<char, vector<pair<char, int>>> &graph, char s, vector<vector<int>> &distance)
    {
        queue<pair<int,int>> q;
        q.push({s, 0});

        while(!q.empty())
        {
            int dis = q.front().second;
            int node = q.front().first;
            q.pop();

            for(auto child: graph[node])
            {
                int child_node = child.first;
                int child_dis = child.second;
                if(distance[s-'a'][child_node-'a'] > dis + child_dis)
                {
                    distance[s-'a'][child_node-'a'] = dis + child_dis;
                    q.push({child.first, dis + child_dis});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> graph;  // {parent, {child, cost}}
        
        for(int i=0;i<original.size();i++)
        {
            graph[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<int>> distance(26, vector<int>(26, INT_MAX));

        for(auto a: original)
        {
            bfs(graph, a, distance);
        }

        int n = source.length();
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            if(source[i] == target[i])
            {
                continue;
            }

            if(distance[source[i]-'a'][target[i]-'a'] == INT_MAX)
            {
                return -1;
            }
            else
            {
                ans += distance[source[i]-'a'][target[i]-'a'];
            }
        }

        return ans;
    }
};