// Frequency Game

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        
        int minFreq = 1e9;
        int ans=-1e9;
        for(int i=0;i<n;i++)
        {
            if(freq[arr[i]] < minFreq)
            {
                minFreq = freq[arr[i]];
                ans = arr[i];
            }
            else if(freq[arr[i]] == minFreq && arr[i] > ans)
            {
                ans = arr[i];
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}