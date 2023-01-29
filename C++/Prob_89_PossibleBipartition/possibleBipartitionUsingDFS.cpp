// Possible Bipartition

class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adjacent, vector<int> &color)
    {
        if(color[node]==-1)
            color[node]=1;
        
        for(auto child: adjacent[node])
        {
            if(color[child]==-1)
            {
                color[child]=1-color[node];
                if(dfs(child, adjacent, color))
                {
                    return true;        // means they belongs to the same set -> hence not bipartite
                }
            }
            else if(color[child]==color[node])
            {
                return true;   // means they belongs to the same set -> hence not bipartite
            }
        }

        return false;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>> adjacent(n+1);
        for(auto a: dislikes)
        {
            adjacent[a[0]].push_back(a[1]);
            adjacent[a[1]].push_back(a[0]);
        }

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i, adjacent, color))
                {
                    return false;  // means they belongs to the same set. Hence Bipartition is not possible
                }
            }
        }
        return true;
    }
};