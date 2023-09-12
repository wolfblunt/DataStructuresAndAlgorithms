// Minimize the maximum difference between adjacent elements in an array

#include <bits/stdc++.h> 

int findKMin(vector<int> &arr, int n, int k)
{
    // int minDiff = INT_MAX;
    deque<int> dq;
    // int i = 0;
    vector<int> v; // storing the maximum elements within the window k_new(i.e. n-1-k_old)
    
    for(int i=0;i<n;i++)
    {
        // minDiff = min(minDiff, q.front());
        if(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }
        
        while(!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
        
        if(i>=k-1)
        {
            v.push_back(arr[dq.front()]);
        }
    }

    int minElement = *min_element(v.begin(), v.end()); // extracting the minimum among the maximum values
    return minElement;
}

int maxAdjDifference(vector<int> &arr, int k){
    vector<int> diff;
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        diff.push_back(arr[i+1]-arr[i]);
    }

    return findKMin(diff, n-1, n-1-k); // extracting min(max(diff)) from n-1-k window size
}