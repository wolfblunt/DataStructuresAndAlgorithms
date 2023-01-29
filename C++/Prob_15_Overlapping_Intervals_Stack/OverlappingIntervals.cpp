//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end());
         vector<vector<int>> vi;
         int n = intervals.size();
         vector<int>v;
         v.push_back(intervals[0][0]);
         v.push_back(intervals[0][1]);
         vi.push_back(v);
         for(int i=1;i<n;i++)
         {
            if(v[1]<intervals[i][0])
            {
                v[0] = intervals[i][0];
                v[1] = intervals[i][1];
                vi.push_back(v);
            }
            else
            {
                vi.pop_back();
                int end1 = max(v[1], intervals[i][1]);
                v[1] = end1;
                vi.push_back(v);
            }
         }
         return vi;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends