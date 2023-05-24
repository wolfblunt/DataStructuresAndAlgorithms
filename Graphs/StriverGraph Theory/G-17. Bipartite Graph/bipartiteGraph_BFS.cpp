// Bipartite Graph Using BFS

class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, vector<int> &color, int index)
    {
        queue<int> q;
        q.push(index);
        color[index] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto a: graph[node])
            {
                if(color[a] == -1)
                {
                    q.push(a);
                    color[a] = !color[node];
                }
                else if(color[a] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(checkBipartite(graph, color, i)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};