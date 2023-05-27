// Eventual Safe States Using BFS

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> revGraph(v);
        vector<int> indegree(v,0);

        for(int i=0;i<v;i++)
        {
            for(auto a: graph[i])
            {
                revGraph[a].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> safeNodes;
        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto a: revGraph[node])
            {
                indegree[a]--;
                if(indegree[a]==0)
                {
                    q.push(a);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};