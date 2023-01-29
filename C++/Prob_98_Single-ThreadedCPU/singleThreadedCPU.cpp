// Single-Threaded CPU
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using pp = pair<int,pair<int,int>>;
        vector<pp> v;
        int n = tasks.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({tasks[i][0],{tasks[i][1],i}});
        }
        sort(v.begin(), v.end());
        int i = 0;
        priority_queue<pp, vector<pp>, greater<pp>> pq; //min heap for availability of process till current time
        long long int currTime = v[0].first;
        vector<int> answer;
        while(i<n || !pq.empty())
        {
            while(i<n && currTime >= v[i].first)
            {
                pq.push(make_pair(v[i].second.first, make_pair(v[i].second.second, v[i].first)));
                i++;
            }
            currTime+=pq.top().first;
            answer.push_back(pq.top().second.first);
            pq.pop();
            if(i<n && currTime < v[i].first && pq.empty())
            {
                currTime = v[i].first;
            }
        }
        return answer;
    }
};