// Number of Nodes in the Sub-Tree With the Same Label

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj, string &labels, int curr, int prev, vector<int> &res)
    {
        vector<int> v(26,0);
        v[labels[curr]-'a'] = 1;
        for(auto a: adj[curr])
        {
            if(a!=prev)
            {
                vector<int> temp = dfs(adj, labels, a, curr, res);
                for(int i=0;i<26;i++)
                {
                    v[i] += temp[i];
                }
            }
        }
        res[curr] = v[labels[curr]-'a'];
        return v;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto a: edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> res(n,0);
        dfs(adj, labels, 0, -1, res);
        return res;
    }
};