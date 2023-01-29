#include<bits/stdc++.h>
using namespace std;

// O(n*log n)
class Solution{
    public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = n-1;
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            int index = upper_bound(arr.begin()+i,arr.end(), arr[i]+k) - arr.begin() - 1; // binary search
            ans = min(ans, n-(index-i+1));
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}