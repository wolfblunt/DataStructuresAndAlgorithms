// Bridges In A Graph
#include<bits/stdc++.h>
void dfs(int node, int parent, int &timer, unordered_map<int, list<int>> &adj, vector<int> &discovery, vector<int> &lowDiscovery, unordered_map<int, bool> &visited, vector<vector<int>> &result)
{
    visited[node] = true;
    discovery[node] = lowDiscovery[node] = timer++;
    for(auto neighbor: adj[node])
    {
        if(neighbor==parent)
        {
            continue;
        }
        if(!visited[neighbor])
        {
            dfs(neighbor, node, timer, adj, discovery, lowDiscovery, visited, result);
            lowDiscovery[node] = min(lowDiscovery[node], lowDiscovery[neighbor]);
            // check if edge is bridge
            if(lowDiscovery[neighbor] > discovery[node])
            {
                vector<int> answer;
                answer.push_back(node);
                answer.push_back(neighbor);
                result.push_back(answer);
            }
        }
        else
        {
            // for back edges
            lowDiscovery[node] = min(lowDiscovery[node], discovery[neighbor]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    int n = edges.size();
    for(int i=0;i<n;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> discovery(v,-1);
    vector<int> lowDiscovery(v,-1);
    unordered_map<int, bool> visited;
    int parent=-1;
    int timer=0;
    vector<vector<int>> result;
    // DFS
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i, parent, timer, adj, discovery, lowDiscovery, visited, result);
        }
    }
    return result;
}

// Input

// 5 4  --> vertices, edges
// 0 1
// 3 1
// 1 2
// 3 4

// Output

// 4  --> number of bridges
// 0 1
// 1 2    
// 1 3
// 3 4