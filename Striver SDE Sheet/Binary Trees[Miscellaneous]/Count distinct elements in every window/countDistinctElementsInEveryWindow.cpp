// Count distinct elements in every window

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int, int> um;
    int n = arr.size();
    vector<int> ans;
    
    for(int i=0;i<k;i++)
    {
        um[arr[i]]++;
    }
    ans.push_back(um.size());
    
    for(int i=k;i<n;i++)
    {
        um[arr[i-k]]--;
        if(um[arr[i-k]] == 0)
        {
            um.erase(arr[i-k]);
        }
        um[arr[i]]++;
        ans.push_back(um.size());
    }
    
    return ans;
}
