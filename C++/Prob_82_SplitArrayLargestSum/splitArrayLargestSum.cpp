// Split Array Largest Sum
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int no_of_subarrays_with_max_sum_as_mid(int arr[], int m, int N)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(sum+arr[i]>m)
            {
                count++;
                sum=arr[i];
            }
            else
            {
                sum+=arr[i];
            }
        }
        return count;
    }
  
    int splitArray(int arr[] ,int N, int K) {
        // Time Complexity - n(logs) -> where s is the sum of array.
        int low = INT_MIN;
        int high = 0;
        for(int i=0;i<N;i++)
        {
            high+=arr[i];
            low = max(low, arr[i]);
        }
        int result;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int n = no_of_subarrays_with_max_sum_as_mid(arr, mid, N);
            if(n>K)
            {
                low = mid+1;
            }
            else
            {
                result = mid; // minimize result
                high = mid-1;
            }
        }
        return result;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}