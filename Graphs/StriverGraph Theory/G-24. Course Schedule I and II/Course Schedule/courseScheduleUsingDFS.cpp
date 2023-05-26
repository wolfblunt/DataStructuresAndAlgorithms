// Course Schedule

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int> &visited, vector<int> &pathVisited, int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                if(dfs(adj, visited, pathVisited, a) == true)
                {
                        return true;
                }
            }

            else if(visited[a] && pathVisited[a])
            {
                return true;
            }
        }
        
        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);
	    
	    vector<int> result;
	    
	    for(int i=0;i<numCourses;i++)
	    {
            if(!visited[i])
            {
                bool res = dfs(adj, visited, pathVisited, i);
                if(res == true)  // Cycle Present
                {
                    return false;
                }
            }
	    }
        return true;
    }
};