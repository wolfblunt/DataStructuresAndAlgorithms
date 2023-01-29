// Convert an array to reduced form

#include <bits/stdc++.h>

using namespace std;


class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    vector<vector<int>> v;
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({arr[i],i});
	    }
	    sort(v.begin(), v.end());
	    for(int i=0;i<n;i++)
	    {
	        arr[v[i][1]]=i;
	    }
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}