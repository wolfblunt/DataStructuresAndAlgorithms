// Articulation Point

//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>adj[], unordered_map<int,bool> &visited, vector<int> &discovery, vector<int> &lowDiscovery,
    int &timer, int parent, set<int> &articulationVector)
    {
        visited[node] = true;
        discovery[node] = lowDiscovery[node] = timer++;
        int child=0;
        for(auto neighbor: adj[node])
        {
            if(neighbor == parent)
            {
                continue;
            }
            if(!visited[neighbor])
            {
                dfs(neighbor, adj, visited, discovery, lowDiscovery, timer, node, articulationVector);
                lowDiscovery[node] = min(lowDiscovery[node], lowDiscovery[neighbor]);
                // check for articulation point
                if(lowDiscovery[neighbor] >= discovery[node] && parent!=-1)
                {
                    articulationVector.insert(node);
                }
                child++;
            }
            else
            {
                lowDiscovery[node] = min(lowDiscovery[node], discovery[neighbor]);
            }
        }
        if(parent==-1 && child>1)
        {
            articulationVector.insert(node);
        }
    }
    
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        unordered_map<int,bool> visited;
        vector<int> discovery(v,-1);
        vector<int> lowDiscovery(v,-1);
        int timer = 0;
        int parent = -1;
        set<int> articulationVector;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i, adj, visited, discovery, lowDiscovery, timer, parent, articulationVector);
            }
        }
        vector<int> answer(articulationVector.begin(), articulationVector.end());
        if(answer.size()==0)
        {
            answer.push_back(-1);
        }
        return answer;
    }
};