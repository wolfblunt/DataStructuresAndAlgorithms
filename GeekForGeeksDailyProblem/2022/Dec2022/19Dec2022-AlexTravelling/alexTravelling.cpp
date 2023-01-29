//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        map<int,vector<pair<int,int>>> graph;
        for(int i=0;i<flights.size();i++)
        {
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        vector<int> destination(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        destination[k]=0;
        pq.push(make_pair(0,k));
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto a: graph[u])
            {
                int v = a.first;
                int weight = a.second;
                
                if(destination[v] > destination[u]+weight)
                {
                    destination[v] = destination[u]+ weight;
                    pq.push(make_pair(destination[v], v));
                }
            }
        }
        
        int maxCount=0;
        for(int i=1;i<destination.size();i++)
    	{
    	    if(destination[i]==INT_MAX)
    	        return -1;
    	    else
    	    {
    	        maxCount = max(maxCount, destination[i]);
    	    }
    	}
    	return maxCount;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends