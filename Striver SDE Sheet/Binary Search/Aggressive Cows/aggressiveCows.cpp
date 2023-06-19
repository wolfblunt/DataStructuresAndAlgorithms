// Aggressive Cows

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canPlaceCows(vector<int> &stalls, int dis, int n, int k)
    {
        int coord = stalls[0];
        int place = 1;
        
        for(int i=1;i<n;i++)
        {
            if(stalls[i] - coord >= dis)
            {
                coord = stalls[i];
                place++;
            }
        }
        
        if(place >= k)
        {
            return true;
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        while(low<=high)
        {
            int mid = (low+high) >> 1;
            if(canPlaceCows(stalls, mid, n, k))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return high;
    }
};


int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}