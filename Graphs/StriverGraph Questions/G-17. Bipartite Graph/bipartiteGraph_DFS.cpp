// Bipartite Graph Using DFS

class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, vector<int> &color, int index)
    {
        for(auto a: graph[index])
        {
            if(color[a] == -1)
            {
                color[a] = !color[index];
                if(checkBipartiteDFS(graph, color, a) == false)
                {
                    return false;
                }
            }
            else if(color[a] == color[index])
            {
                return false;
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
                color[i] = 0;
                if(checkBipartiteDFS(graph, color, i) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};