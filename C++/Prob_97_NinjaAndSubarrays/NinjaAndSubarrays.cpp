#include <bits/stdc++.h> 
int sumOfSmallestAndSecondSmallest(int n, vector<int> &arr){
    int ans=0;
    for(int i=1;i<n;i++)
    {
        ans = max(arr[i]+arr[i-1], ans);
    }
    return ans;
}