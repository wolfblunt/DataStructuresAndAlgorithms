// Circle of strings - O(n)

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int node)
    {
        visited[node] = 1;
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                dfs(adj, visited, a);
            }
        }
    }
  
    int isCircle(vector<string> &arr) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        int n = arr.size();
        
        // Step 1: Create a adjacency list, indegree and outdegree
        for(auto a: arr)
        {
            int u = a[0]-'a';
            int v = a[a.length()-1]-'a';
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // Step 2: If indegree and outdegree of any node is not equal then circle is impossible
        // adj[i].size() -> use as a outdegree -> dimaag laga thoda use kar sakte hai isko
        for(int i=0;i<26;i++)
        {
            if(adj[i].size() != indegree[i])
            {
                return 0;
            }
        }
        
        // Step 3: Check for strongly connected component
        vector<int> visited(26,0);
        dfs(adj, visited, arr[0][0]-'a');
        
        // Step 4: If any node whose indegree or outdeg is not zero and not visited then circle is impossible
        for(int i=0;i<26;i++)
        {
            if(indegree[i] && !visited[i])
            {
                return 0;
            }
        }
        
        return 1;
    }
};