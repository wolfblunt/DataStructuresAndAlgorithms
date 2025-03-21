// Hills and Soldier - O(n)

#include <bits/stdc++.h> 
int countPairs(int n, vector < int > &hills) {
    stack<pair<int,int>> s;  // [height of the hill, no. Of hills it can see]
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && hills[s.top().first] < hills[i])
        {
            ans+=s.top().second;
            s.pop();
        }

        if(s.empty())
        {
            s.push({i, 1});
        }
        else if(hills[s.top().first] == hills[i])
        {
            ans+=s.top().second;
            if(s.size() > 1)
            {
                ans++;
            }
            s.top().second++;
        }
        else
        {
            ans++;
            s.push({i, 1});
        }
    }

    return ans;
}