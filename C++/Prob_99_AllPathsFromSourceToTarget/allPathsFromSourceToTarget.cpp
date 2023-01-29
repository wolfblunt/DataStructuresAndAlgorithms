// All Paths From Source to Target

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>> &shortestPaths, vector<int> tempPath, int source, int dest)
    {
        tempPath.push_back(source);
        if(source==dest)
        {
            shortestPaths.push_back(tempPath);
            return;
        }

        for(auto node: graph[source])
        {
            dfs(graph, shortestPaths, tempPath, node, dest);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> shortestPaths;
        vector<int> tempPath;
        int n = graph.size();
        if(n==0)
            return shortestPaths;
        int source=0;
        dfs(graph, shortestPaths, tempPath, source, n-1);
        return shortestPaths;
    }
};