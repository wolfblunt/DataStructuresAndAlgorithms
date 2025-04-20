// Graph is Tree or Not - O(m+n)

/*
An undirected graph is a tree if it has the following properties. 

1. There is no cycle. 
2. The graph is connected.
*/

class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        vector<vector<int>> adjList(n);
        for(auto a: adj)
        {
            adjList[a[0]].push_back(a[1]);
            adjList[a[1]].push_back(a[0]);
        }
        
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto a: adjList[node])
            {
                if(!visited[a] && a!=parent)
                {
                    q.push({a, node});
                    visited[a] = true;
                }
                else if(a == parent)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        
        return true;
    }
};