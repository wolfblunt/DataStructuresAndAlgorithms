// Eventual Safe States Using DFS

class Solution {
public:
    bool dfsSafeCheck(vector<vector<int>>& graph, vector<int> &visited, vector<int> &pathVisited, vector<int> &safeCheck, int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        safeCheck[node] = 0;

        for(auto a: graph[node])
        {
            if(!visited[a])
            {
                if(dfsSafeCheck(graph, visited, pathVisited, safeCheck, a)==true)
                {
                    safeCheck[node] = 0;
                    return true;
                }
            }
            else if(visited[a] && pathVisited[a])
            {
                safeCheck[node] = 0;
                return true;
            }
        }

        pathVisited[node] = 0;
        safeCheck[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> safeCheck(n,0);
        vector<int> safeNodes;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfsSafeCheck(graph, visited, pathVisited, safeCheck, i);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(safeCheck[i]==1)
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};