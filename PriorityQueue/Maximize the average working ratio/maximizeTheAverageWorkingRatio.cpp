// Maximize the average working ratio

#include <bits/stdc++.h> 
double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    priority_queue<pair<double, int>> pq; // maxHeap
    for(int i=0;i<n;i++)
    {
        double diff = ((double)(bulbs[i][0]+1)/(double)(bulbs[i][1]+1)) - ((double)bulbs[i][0]/(double)bulbs[i][1]);
        pq.push({diff, i});
    }

    double ratio = 0.0;
    while(extra)
    {
        int index = pq.top().second;
        pq.pop();
        bulbs[index][0]+=1;
        bulbs[index][1]+=1;
        double diff = ((double)(bulbs[index][0]+1)/(double)(bulbs[index][1]+1)) - ((double)bulbs[index][0]/(double)bulbs[index][1]);
        pq.push({diff, index});
        extra--;
    }

    for(int i=0;i<n;i++)
    {
        ratio += ((double)bulbs[i][0]/(double)bulbs[i][1]);
    }

    return (ratio/(double)n);
}