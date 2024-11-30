// Valid Arrangement of Pairs - O(V+E)

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    void euler(unordered_map<int, stack<int>>& adj, vector<vector<int>>& ans, int curr) {
        auto& stk = adj[curr];
        while (!stk.empty()) 
        {
            int nei = stk.top();
            stk.pop();
            euler(adj, ans, nei);
            ans.push_back({curr, nei});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        // Eulerian Path
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> in;
        unordered_map<int, int> out;
		
        for (int i = 0; i < m; i++) 
        {
            int u = pairs[i][0];
            int v = pairs[i][1];
            in[v]++;
            out[u]++;
            adj[u].push(v);
        }

		// find the starting node
        int start = -1;
        for (auto& p : adj) 
        {
            int i = p.first;
            if (out[i] - in[i] == 1)
            {
                start = i;
            }
        }
        if (start == -1) 
        {
			// Eulerian Circuit -> start at any node
			start = adj.begin()->first;
        }

        vector<vector<int>> ans;
        euler(adj, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};