// Course Schedule II Using DFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for(auto a: prerequisites)
        {
            adj[a[1]].push_back(a[0]);
            indegree[a[0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto a: adj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0)
                {
                    q.push(a);
                }
            }
        }

        if(topo.size() != numCourses)
        {
            return {};
        }
        return topo;
    }
};