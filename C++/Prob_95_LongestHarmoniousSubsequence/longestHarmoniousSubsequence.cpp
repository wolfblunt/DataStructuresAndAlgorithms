// Longest Harmonious Subsequence

#include<bits/stdc++.h>
int lengthOfLHS(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for(auto a:arr)
    {
        freq[a]++;
    }
    int maxi = 0;

    for(auto a: freq)
    {
        if(freq.count(a.first+1))
            maxi = max(maxi, a.second + freq[a.first+1]);
    }
    return maxi;
}
