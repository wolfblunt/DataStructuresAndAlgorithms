// Minimum Cost Tree

#include<bits/stdc++.h>

long long solve(vector<int> &A) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(A.begin(), A.end());
    long long ans = 0;
    while(pq.size()>1){
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        ans += x+y;
        pq.push(x+y);
    }
    return ans;
}

