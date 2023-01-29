// Zero Sum Subarrays

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long int, int> frequency;
        long long int curr_sum=0;
        long long int count=0;
        frequency[0]++;
        for(int i=0;i<n;i++)
        {
            curr_sum+=arr[i];
            if(!frequency.count(curr_sum))
            {
                frequency[curr_sum] = 1;
            }
            else
            {
                count+=frequency[curr_sum];
                frequency[curr_sum]++;
            }
        }
        return count;
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}