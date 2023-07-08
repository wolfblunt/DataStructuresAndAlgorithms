// Special Subarray

#include <bits/stdc++.h> 
vector<int> specialSubarray(int n, vector<int> &arr)
{
    unordered_map<int, int> um;
    unordered_map<int, int> startIndex;
    unordered_map<int, int> endIndex;
    int maxFreq = 0;
    int start = 0;
    int end = INT_MAX;
    for(int i=0;i<n;i++)
    {
        um[arr[i]]++;
        if(startIndex.find(arr[i]) == startIndex.end())
        {
            startIndex[arr[i]] = i;
        }
        endIndex[arr[i]] = i;
        if(maxFreq < um[arr[i]])
        {
            maxFreq = um[arr[i]];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(um[arr[i]] == maxFreq)
        {
            if(endIndex[arr[i]] - startIndex[arr[i]] < end-start)
            {
                end = endIndex[arr[i]];
                start = startIndex[arr[i]];
            }
        }
    }

    vector<int> ans;
    for(int i=start;i<=end;i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}