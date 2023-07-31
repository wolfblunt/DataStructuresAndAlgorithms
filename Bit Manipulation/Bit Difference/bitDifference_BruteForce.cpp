// bit Difference : O(n^2 * logn)

#include <bits/stdc++.h> 
int differentBitsSumPairwise(vector<int> &arr, int n)
{
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                continue;
            }
            int xorr = arr[i] ^ arr[j];
            int nxor = xorr-1;
            int count = 1;
            while(xorr & nxor)
            {
                xorr = xorr & nxor;
                nxor = xorr-1;
                count++;
            }
            count+=count;
            ans+=count;
        }
    }
    return ans;
}

