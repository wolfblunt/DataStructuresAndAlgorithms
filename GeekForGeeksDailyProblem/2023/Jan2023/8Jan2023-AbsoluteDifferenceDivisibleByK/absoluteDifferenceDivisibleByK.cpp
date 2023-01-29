// Absolute difference divisible by K

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
        {
            um[arr[i]%k]++;
        }
        
        int ans=0;
        for(auto a: um)
        {
            if(a.second==2)
            {
                ans++;
            }
            else
            {
                ans+= (a.second*(a.second-1))/2;
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}