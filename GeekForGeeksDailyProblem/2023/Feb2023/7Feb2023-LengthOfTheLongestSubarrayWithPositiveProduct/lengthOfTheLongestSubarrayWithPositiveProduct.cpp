// Length of the longest subarray with positive product

#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n)
        {
            int ans=0;
            for(int i=0;i<n;)
            {
                int s=i;
                while(s<n && nums[s]==0)
                    s++;
                
                int e=s;
                int c=0;
                int sn=-1; // startNegative
                int en=-1; // endNegative
                while(e<n && nums[e]!=0)
                {
                    if(nums[e]<0)
                    {
                        c++;
                        if(sn==-1)
                            sn=e;
                        en=e;
                    }
                    e++;
                }
                
                if(c%2==0)
                    ans=max(ans,e-s);
                    
                else
                {
                    if(sn!=-1)
                        ans=max(ans,e-sn-1);
                    
                    if(en!=-1)
                        ans=max(ans,en-s);
                }
                i=e+1;
            }
            return ans;
        }
};


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}