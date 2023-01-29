// Longest Path With Different Adjacent Characters

class Solution {
public:
    int dfs(vector<vector<int>>& adj, string &s, int index, int &longestPath)
    {
        int maxnodelength1 = 0;
        int maxnodelength2 = 0;
        for(auto& a: adj[index])
        {
            int currentnodelength = dfs(adj, s, a, longestPath);
            if(s[a] == s[index])
            {
                continue;
            }
            if(currentnodelength > maxnodelength2)
            {
                maxnodelength2 = currentnodelength;
            }
            if(maxnodelength1 < maxnodelength2)
            {
                swap(maxnodelength1, maxnodelength2);
            }
        }
        longestPath = max(longestPath, maxnodelength1 + maxnodelength2 + 1);
        return maxnodelength1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
        }
        int longestPath = 0;
        dfs(adj, s, 0, longestPath);
        return longestPath;
    }
};