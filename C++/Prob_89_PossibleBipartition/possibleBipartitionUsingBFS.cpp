// Possible Bipartition Using BFS

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>> adjacent(n+1);

        for(auto a: dislikes)
        {
            adjacent[a[0]].push_back(a[1]);
            adjacent[a[1]].push_back(a[0]);
        }

        for(int node=1;node<n;node++)
        {
            if(color[node]==-1)
            {
                queue<int> q;
                color[node] = 1;
            
                q.push(node);
                while(!q.empty())
                {
                    int top = q.front();
                    q.pop();
                    for(auto adj: adjacent[top])
                    {
                        if(color[adj] == color[top])
                        {
                            return false;
                        }

                        if(color[adj]==-1)
                        {
                            color[adj] = 1 - color[top];
                            q.push(adj);
                        }
                    } 
                }
            }
        }
        return true;
    }
};