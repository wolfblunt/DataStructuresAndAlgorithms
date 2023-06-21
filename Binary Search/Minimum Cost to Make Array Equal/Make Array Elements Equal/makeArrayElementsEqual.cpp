// Make Array Elements Equal

#include <bits/stdc++.h> 
int findMinimumCost(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int median;
    if(n%2)
    {
        median = arr[n/2];
    }
    else
    {
        median = (arr[n/2] + arr[(n+1)/2])/2;
    }
    int totalCost = 0;
    for(int i=0;i<n;i++)
    {
        totalCost += abs(arr[i] - median);
    }
    return totalCost;
}
