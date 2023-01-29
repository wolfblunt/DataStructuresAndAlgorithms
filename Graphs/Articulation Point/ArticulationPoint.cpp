// Articulation Point
#include<bits/stdc++.h>
using namespace std;

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


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}