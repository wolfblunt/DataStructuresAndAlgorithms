// Maximum Profit By Choosing A Subset Of Intervals

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int searchGreaterOrEqualTo(vector<vector<int>> &a,int val)
    {
        int lo=0;
        int hi=a.size()-1;
        int ans=a.size();
        while(lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if(a[mid][0]<val) {
                lo=mid+1;
            } else {
                hi=mid-1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
    
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        vector<int> dp(n);
        sort(intervals.begin(), intervals.end());
        for(int i=n-1;i>=0;i--) {
            int idx = searchGreaterOrEqualTo(intervals,intervals[i][1]);
            if(idx>=dp.size()) {
                dp[i]=intervals[i][2];
            } else {
                dp[i] = intervals[i][2]+dp[idx];
            }
            if(i!=n-1)
            {
                dp[i] = max(dp[i],dp[i+1]);
            }
        }
        return dp[0];
        
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}