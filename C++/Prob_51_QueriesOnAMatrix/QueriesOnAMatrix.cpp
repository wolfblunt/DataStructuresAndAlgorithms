#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        vector<vector<int>> v(n, vector<int>(n,0));
        
        // O(n^3)
        // for(int k=0;k<Queries.size();k++)
        // {
        //     for(int i=Queries[k][0];i<=Queries[k][2];i++)
        //     {
        //         for(int j=Queries[k][1];j<=Queries[k][3];j++)
        //         {
        //             v[i][j]++;
        //         }
        //     }
        // }
        
        // O(n^2)
        for(int k=0;k<Queries.size();k++)
        {
            int a = Queries[k][0];
            int b = Queries[k][1];
            int c = Queries[k][2];
            int d = Queries[k][3];
            for(int i=a;i<=c;i++)
            {
                v[i][b]++;
                if(d+1<n)
                {
                    v[i][d+1]--;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                v[i][j] = v[i][j-1] + v[i][j];
            }
        }
        return v;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}