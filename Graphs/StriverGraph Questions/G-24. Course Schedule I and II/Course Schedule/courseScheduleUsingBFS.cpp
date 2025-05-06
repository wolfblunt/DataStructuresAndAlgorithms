// Course Schedule: O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for(auto a: adj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0)
                {
                    q.push(a);
                }
            }
        }

        if(count == numCourses)
        {
            return true;
        }

        return false;
    }
};