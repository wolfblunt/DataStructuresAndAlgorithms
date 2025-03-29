// Job Sequencing Problem : O(n*logn) Using Priority Queue

#include<bits/stdc++.h>

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({deadline[i], profit[i]});
        }
        
        sort(v.begin(), v.end());
        
        int totalJobs = 0;
        int totalProfit = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a: v)
        {
            if(pq.size() < a.first)
            {
                pq.push(a.second);
            }
            else if(!pq.empty() && pq.top() < a.second)
            {
                pq.pop();
                pq.push(a.second);
            }
        }
        
        while(!pq.empty())
        {
            totalProfit += pq.top();
            totalJobs++;
            pq.pop();
        }
        
        return {totalJobs, totalProfit};
        
    }
};