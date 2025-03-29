// Count the Number of Complete Components Using BFS : O(V+E)

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto a: edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        vector<bool> visited(n, false);
        int connectedComponentCount = 0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for(auto a: adj[node])
                    {
                        if(!visited[a])
                        {
                            q.push(a);
                            visited[a] = true;
                        }
                    }
                }

                bool isComplete = true;

                for(auto a: component)
                {
                    if(adj[a].size() != component.size()-1)
                    {
                        isComplete = false;
                        break;
                    }
                }

                if(isComplete)
                {
                    connectedComponentCount++;
                }
            }
        }

        return connectedComponentCount;
    }
};