// Alien Dictionary  - Using Topological Sort - DFS and BFS approach

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> topoSortBFS(vector<vector<int>> adj, int n)
    {
        vector<int> indegree(n, 0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            for(auto a: adj[i])
            {
                indegree[a]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> sortResult;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            sortResult.push_back(node);
            for(auto a: adj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0)
                {
                    q.push(a);
                }
            }
        }
        
        return sortResult;
    }
    
    
    // ##################################### Using DFS ####################################
    void helperDFS(vector<vector<int>> &adj, vector<int> &visited, stack<int> &s, int node)
    {
        visited[node] = 1;
        
        for(auto a: adj[node])
        {
            if(!visited[a])
            {
                helperDFS(adj, visited, s, a);
            }
        }
        
        s.push(node);
    }
    
    vector<int> topoSortDFS(vector<vector<int>> &adj, int n)
    {
        vector<int> visited(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                helperDFS(adj, visited, s, i);
        }
        
        vector<int> result;
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
    
    // #####################################################################################
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i=0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        // vector<int> v = topoSortDFS(adj, K);
        vector<int> v = topoSortBFS(adj, K);
        
        string sortans = "";
        for(int i=0;i<v.size();i++)
        {
            sortans += char(v[i] + 'a');
        }
        
        return sortans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}