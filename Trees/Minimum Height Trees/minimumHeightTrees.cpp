// Minimum Height Trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
        {
            return {};
        }
        if(n==1)
        {
            return {0};
        }
        vector<int> ans(n);
        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);

        for(auto a: edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
            degrees[a[0]]++;
            degrees[a[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degrees[i] == 1)
            {
                q.push(i); // storing all the leaf nodes
            }
        }

        while(!q.empty())
        {
            ans.clear();  // clearing all the previous level node
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto a: adj[node])
                {
                    degrees[a]--;
                    if(degrees[a] == 1)
                    {
                        q.push(a);
                    }
                }
            }
        }


        return ans; // storing all the roots of MHTs
    }
};