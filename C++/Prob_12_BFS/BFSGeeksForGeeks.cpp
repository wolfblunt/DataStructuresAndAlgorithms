//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[], int s) {
        vector<bool> v;
        vector<int> answer;
        v.assign(V, false);
        queue<int> q;
        q.push(0);
        v[s] = true;
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            answer.push_back(f);
            for(auto i:adj[f])
            {
                if(!v[i])
                {
                    q.push(i);
                    v[i] = true;
                }
            }
            
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            //      adj[v].push_back(u);
        }
        string source;
        cin>>source;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj, source);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends